n, q = map(int, input().split())
p = [input().split() for _ in range(n)]
t = i = 0
while n:
    i = i % n
    if int(p[i][1]) <= q:
        t += int(p[i][1])
        print(p[i][0], t)
        del p[i]
        n -= 1
    else:
        p[i][1] = int(p[i][1]) - q
        t += q
        i += 1