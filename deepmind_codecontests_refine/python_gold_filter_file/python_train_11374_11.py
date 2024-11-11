for _ in range(int(input())):
    n, m = map(int, input().split())
    a = [[] for i in range(n)]
    for i in range(n): a[i] = list(map(int, input().split()))
    ra = list(reversed([list(reversed(i)) for i in a]))
    ans = 0
    sm = (n + m - 1) // 2
    for s in range(sm):
        cnt0, cnt1 = 0, 0
        for i in range(s + 1):
            if i >= n: continue
            if s - i >= m: continue
            if a[i][s - i] == 0: cnt0 += 1
            if a[i][s - i] == 1: cnt1 += 1
            if ra[i][s - i] == 0: cnt0 += 1
            if ra[i][s - i] == 1: cnt1 += 1

        ans += min(cnt0, cnt1)
    print(ans)












