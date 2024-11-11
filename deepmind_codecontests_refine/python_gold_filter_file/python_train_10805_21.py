import sys
input = sys.stdin.readline
n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
ans = 0
r = set(list(range(n)))
N = n*(n-1) // 2 + 1
for _ in range(N):
    if not r:
        print(_)
        break
    ne = set()
    flag = True
    for j in r:
        if not a[j]:
            continue
        c = a[j][0]
        if c == "-":
            continue
        if j + 1 == a[c-1][0]:
            a[j][0] = "-"
            a[c-1][0] = "-"
            ne.add(j)
            ne.add(c-1)
    for j in list(ne):
        if a[j]:
            if a[j][0] == "-":
                a[j].pop(0)
                flag = False
                if not a[j]:
                    ne.remove(j)
    if flag:
        print(-1)
        break
    else:
        r = ne
