import sys
input = sys.stdin.readline
for _ in range(int(input())):
    aux = input()
    m,n = map(int,input().split())
    mat = []
    for i in range(m):
        l = list(map(int,input().split()))
        mat.append(l)

    d = {}
    h = {}
    s = set()
    flag = 0
    cnt = 10**18
    for i in range(n):
        som = -1
        c = {}
        for j in range(m):
            if mat[j][i] in c:
                c[mat[j][i]].append(j)

            else:
                c[mat[j][i]] = [j]

            if mat[j][i] > som:
                som = mat[j][i]

        d[i] = som
        h[i] = c[som]
        cnt = min(cnt,som)
        for x in h[i]:
            if x in s:
                flag = 1
                break

            s.add(x)

    if flag:
        print(cnt)
        continue

    ans = -1
    for i in range(m):
        o = mat[i]
        o.sort()
        ans = max(ans,min(cnt,o[-2]))

    print(ans)
