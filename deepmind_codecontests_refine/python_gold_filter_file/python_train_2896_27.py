n, k = map(int, input().split())
a = list(map(int, input().split()))
c = [0] * (n+1)
for i in range(n):
    c[i+1] = c[i] + a[i]

s = []
for i in range(n):
    for j in range(i+1, n+1):
        s.append(c[j]-c[i])
s.sort()

L = 40
b = [set() for _ in range(L)]
u = set(range(len(s)))
ans = 0

for i in range(L):
    for j, x in enumerate(s):
        if x >> i & 1:
            b[i].add(j)

for i in range(L)[::-1]:
    if len(u & b[i]) >= k:
        u &= b[i]
        ans += 2**i

print(ans)
