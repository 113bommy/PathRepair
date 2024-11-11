for _ in range(int(input())):
    q = input().split()
    a = int(q[0])
    b = int(q[1])
    e = input()
    d = e.split('1')
    z = 0
    for i in range(1, len(d) - 1):
        f = len(d[i])
        if f >= (b * 2 + 1):
            z += 1
            f = f - b - b - 1
            z += f // (b + 1)
    f = len(d[0])
    if len(d) == 1:
        z += 1
        f -= 1
    if e[0] == '0' and f >= 1 + b:
        z += f // (b + 1)
    f = len(d[-1])
    if e[-1] == '0' and f >= 1 + b and len(d) != 1:
        z += f // (b + 1)
    if e == '00' or e == '0':
        z = 1
    print(z)