MOD=10**9+7
a,b,n,x=map(int,input().split())

if a==1:
    print((x+n*b)%MOD)
    exit()
t=pow(a,n,MOD*(a-1))
print((t*x+b*(t-1)//(a-1))%MOD)