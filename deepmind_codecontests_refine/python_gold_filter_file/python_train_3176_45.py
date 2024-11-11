found=1
n,k=map(int,input().split())
if(n==1):
    if(k<=9):
        print(k)
    else:
        print(-1)
    found=0
else:
    s=1
    for i in range(n-1):
        s=s*10+0
    for i in range(s+1,s+100,1):
        if(i%k==0):
            print(i)
            found=0
            break
    if(found==1):
        print(-1)