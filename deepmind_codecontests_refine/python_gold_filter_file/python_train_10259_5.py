a,b,n,x=map(int,input().split())
m=10**9+7
if a != 1:
    print((pow(a, n, m)*x + b * ((pow(a, n, m) - 1) * pow(a - 1, m - 2, m)))%m)
else:
    print((b*n+x)%m)