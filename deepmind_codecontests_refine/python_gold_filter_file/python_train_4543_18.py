mod=1000000007
n,m,k=list(map(int,input().split()))
if k==-1:
    co=n+m
    if co%2!=0:
      print("0")
    else:
      n=n-1
      m=m-1
      n=n*m
      co=pow(2,n,mod)
      co%=1000000007
      print(co)
else:
    n=n-1
    m=m-1
    n=n*m
    co=pow(2,n,mod)
    co%=1000000007
    print(co)