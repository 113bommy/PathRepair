a, b, d = [int(i) for i in input().split()]
try:
    if (b - a) % d == 0 and (b-a)/d >= 0 : print('YES')
    else: print('NO')
except:
    if a == b: print('YES')
    else: print('NO')
