##n = int(input())
##a = list(map(int, input().split()))
##print(' '.join(map(str, res)))

[ax, ay, bx, by, cx, cy] = list(map(int, input().split()))
dx1 = ax-bx
dy1 = ay-by
dx2 = cx-bx
dy2 = cy-by
if dx1*dy2 == dx2*dy1 or dx1*dx1+dy1*dy1 != dx2*dx2+dy2*dy2:
    print('no')
else:
    print('yes')
