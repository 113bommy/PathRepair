while True:
    n = int(input())
    if n == 0:break
    c = {}
    for _ in range(n):
        a,b = input().split()
        c[a] = b
    m = int(input())
    ans = ''
    for _ in range(m):
        a = input()[0]
        ans+=c[a] if a in c else a
    print(ans)