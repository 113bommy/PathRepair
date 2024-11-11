def get_coords(a, v):
    coords = {}
    for i in range(len(a)):
        for j in range(len(v)):
            crd = (a[i][0] + v[j][0], a[i][1] + v[j][1])
            if crd not in coords:
                coords[crd] = 1
            else:
                coords[crd] += 1

            if coords[crd] == len(a):
                return crd

    return 5000000, 5000000       # для отладки


n = int(input())

obelisks = [tuple(map(int, input().split())) for i in range(n)]
tips = [tuple(map(int, input().split())) for i in range(n)]

print(*get_coords(obelisks, tips))
