for _ in range(int(input())):
    k, n, a, b = [int(i) for i in input().split()]
    if n*b >= k:
        print(-1)
    else:
        print(min((k - b * n - 1)//(a - b), n))
