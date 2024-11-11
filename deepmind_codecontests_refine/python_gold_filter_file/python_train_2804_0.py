while True:
    n = int(input())
    if n == 0:
        break
    a = sorted(list(map(int, input().split())))
    ans = 1000001
    for i in range(n - 1):
        j = a[i + 1] - a[i]
        if j < ans:
            ans = j
    print(ans)