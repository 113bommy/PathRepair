import sys

def ii():
    return sys.stdin.readline().strip()

def idata():
    return [int(x) for x in ii().split()]

def solve_of_problem():
    n, x = idata()
    data = idata()
    q, w = -1, n
    if sum(data) % x != 0:
        print(n)
        return
    for i in range(n):
        if data[i] % x != 0:
            q = i
            break
    for i in range(n - 1, -1, -1):
        if data[i] % x != 0:
            w = i
            break
    if w == n and q == -1:
        print(-1)
    else:
        print(max(n - q - 1, w))
    return

for ______ in range(int(ii())):
    solve_of_problem()
