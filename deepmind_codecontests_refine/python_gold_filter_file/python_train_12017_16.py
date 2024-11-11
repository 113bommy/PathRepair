n=list(input());
if '+' in n:
    t=n.index('+');
elif '-' in n:
    t=n.index('-');
e=n.index('=');
f=t;
s=e-1-t;
a=len(n)-2-s-f;
if '+' in n:
    if (f+s==a):
        for i in n:
            print(i,end="")
    elif (a-f-s==2):
        n=["|"]+n[0:len(n)-1];
        for i in n:
            print(i,end="")
    elif(s+f-a==2):
        if f>=2:
            n=n[1:len(n)]+["|"]
        else:
            n=n[0:t+1]+n[t+2:e+1]+n[e+1:len(n)]+["|"]
        for i in n:
                print(i,end="")
    else:
        print("Impossible")
    
