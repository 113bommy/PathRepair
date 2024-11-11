st, nd = input().split()
n = int(input())
x = ['<', '^', '>', 'v']

st = x.index(st)
nd = x.index(nd)

if (st + nd) % 2 == 0:
    print('undefined')
else:
    n %= 4
    if (st + n) % 4 == nd:
        print('cw')
    else:
        print('ccw')
