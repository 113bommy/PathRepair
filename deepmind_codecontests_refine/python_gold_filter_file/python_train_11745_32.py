def f(n,x):
    if n == 0:return 0 if x <= 0 else 1
    elif x <= 1+b[n-1]: return f(n-1, x-1)
    else:
        return 1+p[n-1]+f(n-1,x-2-b[n-1])

N,X=map(int,input().split())
b,p = [1 for _ in range(N+1)],[1 for _ in range(N+1)]

for i in range(1,N+1):
    b[i] = b[i-1]*2+3
    p[i] = p[i-1]*2+1
print(f(N,X))