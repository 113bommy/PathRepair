n, k = map(int, input().split())

if k > n: print(-1)
elif k == n: print(0, 0)
else:
    t = list(map(int, input().split()))
    t.sort()
    if t[n - k] != t[n - k - 1]: print(t[n - k], t[n - k])