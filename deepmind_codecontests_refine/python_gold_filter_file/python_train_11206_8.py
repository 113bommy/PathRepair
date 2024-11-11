n,k = map(int,input().split())
if(k==1):
    print("Yes")
elif(k>100):
    print("No")
else:
    c=1
    for i in range(1,k+1):
        if((n+1)%i != 0):
            c=0
    if(c==1):
        print("Yes")
    else:
        print("No")