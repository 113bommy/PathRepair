n, k = [int(x) for x in input().split(' ')]
ans = max(min(n - (k - 2 * n), n), 0)
print(ans)