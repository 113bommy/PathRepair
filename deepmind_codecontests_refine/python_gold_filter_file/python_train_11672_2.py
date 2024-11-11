I=lambda:map(int,input().split())
n,m,k,l=I()
if m>n or (l>=n) :
    print(-1)
else:
    x= (-(-(l+k)//m))
    if x*m>n:
        print(-1)
    else:
        print(x)