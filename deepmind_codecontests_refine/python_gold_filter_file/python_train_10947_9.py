q = int(input());

while (q>0):
    n=int(input());

    flag = 0;
    count=0;
    while (n>1 and flag==0):
        if(n%2 == 0):
            n=n//2;
            count = count+1;
        elif(n%3==0):
            n=n//3;
            count = count+2;
        elif(n%5 == 0):
            n=n//5;
            count = count+3;
        else:
            flag = 1;
    
    if flag==0 and n>0:print(count);
    else: print(-1);
    q=q-1; 