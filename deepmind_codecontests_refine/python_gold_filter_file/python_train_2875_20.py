n, k = map(int,input().split())
worst = 1 if 1 <= k < n else 0
best = min(n-k, 2*k)
print(worst, best)