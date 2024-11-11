def main():
    n = int(input())
    ab = [list(map(int, input().split())) for _ in [0]*(n-1)]
    g = [[] for _ in [0]*n]
    [g[a-1].append(b-1) for a, b in ab]
    [g[b-1].append(a-1) for a, b in ab]

    root = 0  # 根
    d = [-1]*n  # 根からの距離
    d[root] = 0
    q = [root]
    cnt = 0
    while q:  # BFS
        cnt += 1
        qq = []
        while q:
            i = q.pop()
            for j in g[i]:
                if d[j] == -1:
                    d[j] = cnt
                    qq.append(j)
        q = qq
    d = [i % 2+1 for i in d]
    d2 = [0]*n
    x = d.count(1)
    y = d.count(2)
    if x > n//3 and y > n//3:
        j1 = 1
        for i in range(n):
            if d[i] == 1:
                d2[i] = j1
                j1 += 3
                cnt += 1
        j2 = 2
        for i in range(n):
            if d[i] == 2:
                d2[i] = j2
                j2 += 3
        j3 = 3
        for i in range(n):
            if d2[i] > n:
                d2[i] = j3
                j3 += 3
    elif x <= n//3:
        j3 = 3
        for i in range(n):
            if d[i] == 1:
                d2[i] = j3
                j3 += 3
        j2 = 1
        for i in range(n):
            if d[i] == 2:
                d2[i] = j2
                if j2 % 3 == 2:
                    j2 += 2
                else:
                    j2 += 1
        for i in range(n):
            if d2[i] > n:
                d2[i] = j3
                j3 += 3
    else:
        j3 = 3
        for i in range(n):
            if d[i] == 2:
                d2[i] = j3
                j3 += 3
        j2 = 1
        for i in range(n):
            if d[i] == 1:
                d2[i] = j2
                if j2 % 3 == 2:
                    j2 += 2
                else:
                    j2 += 1
        for i in range(n):
            if d2[i] > n:
                d2[i] = j3
                j3 += 3
    print(*d2)


main()