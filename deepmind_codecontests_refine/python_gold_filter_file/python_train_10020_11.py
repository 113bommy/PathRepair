def f(x, d):
    d += 1
    c[x] = 0
    if d > maxd[0]:
        maxd[0] = d
    if d >= 2:
        maxd[1] += 1
    if len(p[x]) == 1:
        return
    for i in p[x]:
        if c[i] == 1:
            f(i, d)



# list(map(int, input().split()))
rw = int(input())
for ewq in range(rw):
    n1 = 'Ayush'
    n2 = 'Ashish'
    n, x = map(int, input().split())
    if n == 1:
        print(n1)
        continue
    x -= 1
    g = [[]for i in range(n - 1)]
    for i in range(n - 1):
        a, b = map(int, input().split())
        g[i] = [a - 1, b - 1]
    p = {}
    for i in range(n):
        p[i] = []
    for i in g:
        p[i[0]].append(i[1])
        p[i[1]].append(i[0])
    l = []
    c = [1] * n
    maxd = [0, 0]
    f(x, 0)
    if len(p[x]) == 1:
        print(n1)
        continue
    if (maxd[1] - 1) % 2 == 0:
        print(n1)
    else:
        print(n2)