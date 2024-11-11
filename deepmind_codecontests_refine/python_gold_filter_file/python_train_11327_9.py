n, m = map(int, input().split())
a = [(1, int(i)) for i in input().split()]
for _ in range(m):
    b, c = map(int, input().split())
    a.append((b, c))
a = sorted(a, key=lambda x: x[1])
res = 0
idx = 0
while idx < n:
    b, c = a.pop()
    p = min(b, n-idx)
    res += p * c
    idx += p
print(res)
