R = lambda: map(int, input().split())
n = int(input())
arr = list(R())
l, r, s = max(arr), len(arr) * max(arr), sum(arr)
while l < r:
    m = (l + r) // 2
    if m * n - s >= m:
        r = m
    else:
        l = m + 1
print(l)