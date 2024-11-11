n,m,k = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
t = sum(b)
ans = 0
j = m

for i in range(n+1):
    while j > 0 and t>k:
        j -= 1
        t -= b[j]
    if t>k: break
    ans = max(ans, i+j)
    if i==n: break
    t += a[i]

print(ans)
