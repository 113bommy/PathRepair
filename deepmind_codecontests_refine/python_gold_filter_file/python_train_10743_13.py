t = int(input())
for _ in range(t):
    n, m = [int(x) for x in input().split()]
    a = [int(a) for a in input().split()]
    if n == 2 or n > m:
        print("-1")
        continue
    ans = 0
    for key in a:
        ans += key * 2
    b = sorted(a)
    ans += (m - n) * (b[0] + b[1])
    print(ans)
    for i in range(1, n):
        print(str(i) + ' ' + str(i + 1))
    print(str(1) + ' ' + str(n))
    for i in range(m - n):
        print(str(a.index(b[0] + 1)) + ' ' + str(a.index(b[1] + 1)))