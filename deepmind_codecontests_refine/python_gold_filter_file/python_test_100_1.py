for _ in range(int(input())):
    n = int(input())
    x = list(map(int, input().split()))
    if n == 1: ans = x[0]
    else:
        x = sorted(x)
        ans = x[0]
        for i in range(1, n):
            xd = x[i] - x[i-1]
            if xd > ans : ans = xd
    print(ans)