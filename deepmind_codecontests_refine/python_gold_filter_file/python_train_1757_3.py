import math

k = 1.0/math.sqrt(2.0)
while True:
    n = int(input())
    if n == -1:
        break
    nx = 1.0
    ny = 0.0
    for i in range(n-1):
        dx = -ny
        dy = nx
        d = 1.0/math.sqrt(dx**2 + dy**2)
        nx = nx + d*dx
        ny = ny + d*dy
    print(nx)
    print(ny)


