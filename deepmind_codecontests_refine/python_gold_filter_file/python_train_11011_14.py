n, k = map(int, input().split())
a = list(map(int, input().split()))
current = a[:]
for _ in range(min(42, k)):
    nex = [0]*n
    for i, v in enumerate(current):
        l = max(0, i-v)
        r = min(n-1, i+v)
        nex[l] += 1
        if r+1 < n:
            nex[r+1] -= 1
    for i in range(1, n):
        nex[i] += nex[i-1]
    current = nex

print(*current)