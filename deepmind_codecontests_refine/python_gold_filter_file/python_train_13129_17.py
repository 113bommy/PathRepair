import sys

t = int(sys.stdin.readline().strip())
for i in range (0, t):
    line = sys.stdin.readline().split()
    n = int(line[0])
    x = int(line[1])
    y = int(line[2])
    d = int(line[3])
    z = -1
    if (x - y) % d == 0:
        z = abs((x - y)//d)
    if (1 - y) % d == 0:
        z2 = (y-1)//d + (x-1)//d + 1
        if z != -1:
            z = min(z,z2)
        else:
            z = z2
    if (n - y) % d == 0:
        z3 = (n-y)//d + (n-x)//d + 1
        if z != -1:
            z = min(z,z3)
        else:
            z = z3
    print(z)
