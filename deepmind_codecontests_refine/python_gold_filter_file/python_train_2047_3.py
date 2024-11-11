n,m,k=map(int,input().split())
if k<=n-1:
    print(k+1,1)
else:
    k-=n-1
    m-=1 
    q=(k-1)//m 
    r=(k-1)%m 
    if q%2==0:
        print(n-q,r+2)
    else:
        print(n-q,m+1-r)