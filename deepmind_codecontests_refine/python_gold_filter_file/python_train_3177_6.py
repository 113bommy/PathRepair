a, b, c = map(int, input().split())
x, y, z = map(int, input().split())
r = [a - x, b - y, c - z]
r.sort()
if r[2] < 0:
    print('No')
elif r[1] < 0:
    if r[2] // 2 >= -(r[0] + r[1]):
        print('Yes')
    else:
        print('No')
elif r[0] < 0:
    if r[2] // 2 + r[1] // 2 >= -r[0]:
        print('Yes')
    else:
        print('No')
else:
    print('Yes')