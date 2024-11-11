import sys
eps = 0.00001

def expect(c, m, p, v, itr):
    ###print('checking: ', c, m, p, v)
    if abs(c) < eps and abs(m) < eps:
        return itr * p
    if abs(c) < eps:
        mv = max(m - v, 0)
        return itr * p + m * expect(0, mv, p + m - mv, v, itr + 1)
    if abs(m) < eps:
        cv = max(c - v, 0)
        return itr * p + c * expect(cv, 0, p + c - cv, v, itr + 1)
    cv = max(c - v, 0)
    mv = max(m - v, 0)
    dc = (c - cv) / 2
    dm = (m - mv) / 2
    return itr * p + c * expect(cv, m + dc, p + dc, v, itr + 1) + m * expect(c + dm, mv, p + dm, v, itr + 1)
    
    
t = int(input())
for _ in range(t):
    q = list(map(float, input().split()))
    print(expect(q[0], q[1], q[2], q[3], 1))