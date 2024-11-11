while True:
    n = int(input())
    if n == 0:
        break
    d = {}
    for _ in range(n):
        a, b = input().split()
        d[a] = b
    m = int(input())
    ans = ""
    for _ in range(m):
        a = input().strip()
        ans += d.get(a, a)
    print(ans)