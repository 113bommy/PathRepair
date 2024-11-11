n,m,d=list(map(int,input().split()))

if d==0:
    R=n
else:
    R=2*(n-d)

print(R*(m-1)/n**2)
