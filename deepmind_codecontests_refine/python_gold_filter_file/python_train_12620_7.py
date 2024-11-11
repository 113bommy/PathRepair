n = int(input())
a = [int(i) for i in input().split()]
mx = -1
good = []
for i in range(n):
    s = a[i]
    now = a.copy()
    for j in range(i - 1, -1, -1):
        now[j] = min(a[j], now[j + 1])
        s += now[j]
    for j in range(i + 1, n):
        now[j] = min(a[j], now[j - 1] )
        s += now[j]
    if (s > mx):
        good = now.copy()
    mx = max(s, mx)
print(*good)