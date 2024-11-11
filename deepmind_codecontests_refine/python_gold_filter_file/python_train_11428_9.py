from collections import defaultdict
N,X,M = map(int,input().split())
ans = 0
d = defaultdict(lambda:-1)
x = X%M
for n in range(M+100):
    if x in d:
        T = n-d[x]
        break
    else:
        d[x] = n
    x *= x
    x %= M
p = 0
y = x
for m in range(d[x],n):
    p += y
    y *= y
    y %= M

ans = 0
n = N
z = X%M
while n:
    ans += z
    n -= 1
    z *= z
    z %= M
    if z==x:
        ans += n//T*p
        n %= T
print(ans)