for _ in range(int(input())):
    k, n, a, b = map(int, input().split())
    ans = (k - b * n - 1) // (a - b)
    print(min(n, ans) if ans >= 0 else -1)
