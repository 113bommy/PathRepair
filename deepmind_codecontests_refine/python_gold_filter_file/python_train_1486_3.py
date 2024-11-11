n, m = map(int, input().split())
if min(n, m) > 3:
    print(-1)
    exit()
if min(n, m) == 1:
    print(0)
    exit()
if n > m:
    inp = []
    for i in range(n):
        inp.append(list(map(int, input().split())))
    u = []
    n, m = m, n
    for i in range(n):
        u.append([0] * m)
    for i in range(n):
        for j in range(m):
            u[i][j] = inp[j][i]
else:
    u = []
    for i in range(n):
        u.append(list(map(int, list(input()))))
if n == 2:
    d = [0] * m
    for j in range(m):
        if u[0][j] + u[1][j] == 1:
            d[j] = 1
    cnt1 = 0
    cnt2 = 0
    for j in range(m):
        if d[j] % 2 == j % 2:
            cnt1 += 1
        else:
            cnt2 += 1
    print(min(cnt1, cnt2))
else:
    d1 = [0] * m
    d2 = [0] * m
    for j in range(m):
        if u[0][j] + u[1][j] == 1:
            d1[j] = 1
        if u[1][j] + u[2][j] == 1:
            d2[j] = 1
    cnt1 = cnt2 = cnt3 = cnt4 = 0
    for j in range(m):
        r1 = d1[j] % 2 == j % 2
        r2 = d2[j] % 2 == j % 2
        if r1 and r2:
            cnt2 += 1
            cnt3 += 1
            cnt4 += 1
        elif r1:
            cnt1 += 1
            cnt3 += 1
            cnt4 += 1
        elif r2:
            cnt1 += 1
            cnt2 += 1
            cnt4 += 1
        else:
            cnt1 += 1
            cnt2 += 1
            cnt3 += 1
    print(min(cnt1, cnt2, cnt3, cnt4))
    #print(cnt1, cnt2, cnt3, cnt4)
        
