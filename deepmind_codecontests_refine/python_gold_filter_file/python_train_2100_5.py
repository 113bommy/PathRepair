s,b = map(int,input().split())
a = [int(s) for s in input().split()]
dg = [[int(s) for s in input().split()] for i in range(b)]
dg.sort()
for i in range(1,b):
    dg[i][1] += dg[i-1][1]
for i in a:
    left = 0
    right = b-1
    if dg[0][0] > i:
        print(0)
        continue
    if dg[-1][0] <= i:
        print(dg[-1][1])
        continue
    while True:
        m = (left+right)//2
        if m == left:
            print(dg[m][1],end = ' ')
            break
        if dg[m][0] > i:
            right = m
        else:
            left = m