n,k,t = list(map(int, input().split()))
if t <= k:
    print(t)
elif t > k and t <= n:
    print(k)
else:
    p = (n - t) + k
    print(p if p >= 0 else 0)
