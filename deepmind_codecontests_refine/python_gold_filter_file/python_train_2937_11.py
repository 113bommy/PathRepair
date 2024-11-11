def process(r, c):
    if r==1 and c==1:
        return [[0]]
    M = []
    if r <= c:
        for i in range(1, c+1):
            row = []
            for j in range(1, r+1):
                row.append((i+r)*j)
            M.append(row)
    else:
        for i in range(1, c+1):
            row = []
            for j in range(1, r+1):
                row.append(i*(j+c))
            M.append(row)
    return M

r, c = [int(x) for x in input().split()]
M = process(c,r)
for r in M:
    print(' '.join(map(str, r)))