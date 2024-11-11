x, y, z, t1, t2, t3 = map(int, input().split())

st = abs(x-y)*t1
wt = abs(x-y) * t2 + abs(x-z) * t2 + 3*t3

if st < wt:
    print('NO')
else:
    print('YES')



