INF = 10 ** 6

t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    s = list(map(int, input()))

    on_sum = sum(s)
    ans = INF

    for i in range(k):
        cnt = on_sum
        for e in s[i::k]:
            cnt -= e

        off = 0
        off_on = INF
        off_on_off = INF

        for e in s[i::k]:
            off_on_off = min(off_on_off + e, off_on + e)
            off_on = min(off_on + 1 - e, off + 1 - e)
            off = off + e

        cnt += min(off, off_on, off_on_off)

        ans = min(ans, cnt)

    print(ans)
