z = 10**9+9
n,m,k = map(int,input().split())
i = n-m
x = (n-k+1)//k
if k*i>=n-k+1:
    print((n-i)%z)
else:
    l = n-k+1
    f = l-(i-1)*k-1
    t = f//k
    f = t*k
    v = 2*(pow(2,t,z)-1)*k+(n-f-i)
    print(v%z)
