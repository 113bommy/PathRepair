while True:
    n = int(input())
    if n == 0:
        break
    p = [10, 10]
    l = [list(map(int,input().split())) for _ in range(n)]
    for d,s in [input().split() for _ in range(int(input()))]:
        for _ in range(int(s)):
            if d == 'N':
                p[1] += 1
            elif d == 'E':
                p[0] += 1
            elif d == 'W':
                p[0] -= 1
            elif d == 'S':
                p[1] -= 1
            if p in l:
                l.remove(p)
    if len(l) == 0:
        print('Yes')
    else:
        print('No')