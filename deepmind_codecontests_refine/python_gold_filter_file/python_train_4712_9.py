for _ in range(int(input())):
    n, m = map(int, input().split())
    a = sorted(map(int, input().split()))
    b = [0] * (n + 1)
    for i in range(n - 1, -1, -1):
        b[i] = b[i + 1]
        x = (m + a[i] - 1) // a[i]
        if i + x <= n:
            b[i] = max(b[i], 1 + b[i + x])
    print(b[0])
