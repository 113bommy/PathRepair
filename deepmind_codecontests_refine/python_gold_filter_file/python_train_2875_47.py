n,m=map(int,input().split(" "))
r=0
if(n-m>=1):
    r=1
if(m==0):
    print("0 0")
else:
    if(m<=n//3):
        print(r,m*2)
    else:
        print(r,n-m)