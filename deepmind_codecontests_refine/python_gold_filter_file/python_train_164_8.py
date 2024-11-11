from fractions import Fraction

xa, ya, xb, yb, xc, yc = map(int, input().split())

if xa * (yb - yc) + xb * (yc - ya) + xc * (ya - yb) == 0:
    print('NO')
elif (xa - xb)**2 + (ya - yb)**2 == (xb - xc)**2 + (yb - yc)**2:
    print('YES')
else:
    print('NO')