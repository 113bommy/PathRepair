q = int(input())
for qq in range(q):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = []
    for i in range(n):
        b.append([a[i], i+1])
    s = 2 * sum(a)
    b.sort(key=lambda x: x[0])
    if n == 2:
        print(-1)
        continue
    if n > m:
        print(-1)
    else:
        print(s + (b[0][0] + b[1][0]) * (m-n))
        for i in range(n-1):
            print(i+1, i+2)
        print(n, 1)
        for i in range(m-n):
            print(b[0][1], b[1][1])
