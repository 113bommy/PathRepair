H, W, d = [int(x) for x in input().split(" ")]

res = ''

d2 = 2 * d
for h in range(H):
    for w in range(W):
        x = h - w
        y = h + w
        if x % d2 < d:
            c = 'R' if  y % d2 < d else 'B'
        else:
            c = 'G' if  y % d2 < d else 'Y'
        res+= c
    res += '\n'

print(res)
