x, y, l, r = map(int, input().split())
px = [1] * 65
py = [1] * 65
for i in range(1, 65):
    px[i] = px[i - 1] * x
    py[i] = py[i - 1] * y

s = set()
for i in range(65):
    for j in range(65):
        v = px[i] + py[j]
        if l <= v <= r:
            s.add(v)
if not s:
    print(r - l + 1)
    exit(0)
s = sorted(list(s))
result = max(s[0] - l, r - s[-1])
for i in range(1, len(s)):
    result = max(result, s[i] - s[i - 1] - 1)
print(result)
