def f():
    a, b = map(int, input().split())
    A, B = map(int, input().split())
    return ((a, B), (A, b))
def g(u, v): return u[0] > v[1] and u[1] > v[0]
x, y = f(), f()
if any(all(g(j, i) for i in y) for j in x): print('Team 1')
elif all(any(g(i, j) for i in y) for j in x): print('Team 2')
else: print('Draw')
