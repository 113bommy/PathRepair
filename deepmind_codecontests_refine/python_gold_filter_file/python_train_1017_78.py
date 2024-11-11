n, k, s = map(int, input().split())
if s == 10**9:
    arr = [s]*k + [s-1]*(n-k)
else:
    arr = [s]*k + [s+1]*(n-k)

print(*arr)
