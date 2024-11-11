def f(a,b, x,y, z,q):
    res = 0
    if x+z <= a and max(y,q) <= b: res += 1
    if max(x,z) <= a and y+q <= b: res += 1

    return res

a1, b1 = map(int, input().split())
a2, b2 = map(int, input().split())
a3, b3 = map(int, input().split())

res = f(a1,b1,a2,b2,a3,b3) + f(a1,b1,a2,b2,b3,a3) + f(a1,b1,b2,a2,a3,b3) + f(a1,b1,b2,a2,b3,a3) + f(b1,a1,a2,b2,b3,a3) + f(b1,a1,b2,a2,a3,b3) + f(b1,a1,b2,a2,b3,a3) + f(b1,a1,a2,b2,a3,b3)
if res > 0: print('YES')
else: print('NO')
