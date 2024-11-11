for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    s = sum(a)
    if s % n != 0:
        print(-1)
        continue
    b = s // n
    ans = []
    for i in range(1, n):
        x = (i + 1 - (a[i] % (i + 1))) % (i + 1)
        ans += [[1, i + 1, x]]
        a[0] -= x
        a[i] += x
        ans += [[i + 1, 1, a[i] // (i + 1)]]
        a[0] += a[i]
        a[i] = 0
    for i in range(1, n):
        ans += [[1, i + 1, b]]
    print(len(ans))
    [print(*i) for i in ans] 