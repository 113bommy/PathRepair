import sys
input = sys.stdin.readline
for _ in range(1):
    r,c = map(int,input().split())
    if r == 1 and c == 1:
        print(0)
        continue

    if r == 1:
        mat = []
        for i in range(2,c+2):
            mat.append(i)

        print(*mat)
        continue

    if c == 1:
        mat = []
        for i in range(2, r + 2):
            o = []
            o.append(i)
            mat.append(o)

        for i in mat:
            print(*i)

        continue

    mat = []
    for i in range(1,r+1):
        o = []
        for j in range(1,c+1):
            o.append(i*(j+r))

        mat.append(o)

    for i in mat:
        print(*i)