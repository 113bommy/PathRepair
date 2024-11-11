for _ in range(int(input())):
    n, m = map(int, input().split())
    a = [int(x) for x in input().split()]
    if n==2 or m < n:
        print(-1)
        continue
    for i in range(len(a)): a[i] = (a[i], i + 1)
    # a.sort()
    a.append(a[0])
    ans = 0
    anss = []
    pr = 0
    while pr != m:
        for i in range(1, n + 1):
            if pr == m:
                break
            ans += a[i - 1][0] + a[i][0]
            anss.append((a[i - 1][1], a[i][1]))
            pr += 1
    print(ans)
    for i in anss:
        print(*i)
