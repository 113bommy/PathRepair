n = int(input())
a = []
b = []
d = {}
for i in range(n):
    x, y = map(int, input().split())
    d[x] = y
    a.append(x)
    b.append(y)
m = max(a)
ans = [0] * (m + 1)
for i in range(m + 1):
    if d.get(i, -1) == -1:
        ans[i] = ans[i - 1]
    else:
        ans[i] = 1 + (ans[i - d[i] - 1] if i - d[i] - 1 >= 0 else 0)
t = max(ans)
print(n - t)