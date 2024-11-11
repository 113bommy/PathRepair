n, m = map(int, input().split())
a = [(1, int(i)) for i in input().split()]
for _ in range(m):
    b, c = map(int, input().split())
    a.append((b, c))
a = sorted(a, key=lambda x: x[1])
ans = 0
t = 0
while t < n:
    b, c = a.pop()
    p = min(b, n-t)
    ans += p * c
    t += p
print(ans)
