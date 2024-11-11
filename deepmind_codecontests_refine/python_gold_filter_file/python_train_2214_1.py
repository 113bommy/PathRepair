res = ''
for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    c = {}
    r = 0
    for i, row in enumerate(a):
        m = 0 
        for row2 in a[i+1:]:
            if row == row2: r += m
            m += c.get(row2, 0)
        c[row] = c.get(row, 0) + 1
    res += f'{r}\n'
print(res)