n,m=list(map(int,input().split()))
z=[set() for i in range(m)]
mod=10**9+7
for i in range(n):
    s=input()
    for k in range(m):
        z[k].add(s[k])
c=1
for i in z:
    c*=(len(i)%mod)
print(c%mod)
