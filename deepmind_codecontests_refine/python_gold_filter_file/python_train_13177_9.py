n, k = map(int, input().split())
a = list(map(int, input().split()))
s = [0 for i in range(n + 1)]
for i in range(n):
    s[i] = s[i - 1] + a[i]
ans = 0
bg = 1
can = set()
prev = dict()
prev[0] = 1
for i in range(50):
    can.add(bg)
    bg *= k
for i in range(n):
    for j in can:
        if s[i] - j in prev:
            ans += prev[s[i] - j]
    if s[i] in prev:
        prev[s[i]] += 1
    else:
        prev[s[i]] = 1
print(ans)
