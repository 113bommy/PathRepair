def find(n, a, b):
    if abs(a - b) > 1:
        return -1
    if a + b > n-2:
        return -1
    up = [n-i for i in range(a)]
    down = [i+1 for i in range(b)]
    combine = [str(b+1), ]
    if a == b:
        for i in range(a):
            combine.append(str(up[i]))
            combine.append(str(down[i]))
    else:
        c = b
        if a < b:
            up, down = down, up
            c = a
        for i in range(c):
            combine.append(str(up[i]))
            combine.append(str(down[i]))
        combine.append(str(up[-1]))
    if int(combine[-1]) == n-a+1:
        for i in range(n-a, b+1, -1):
            combine.append(str(i))
    else:
        for i in range(b + 2, n - a + 1):
            combine.append(str(i))
    return ' '.join(combine)

cases = int(input())
for y in range(cases):
    line = input().split( )
    n, a, b = int(line[0]), int(line[1]), int(line[2])
    print(find(n, a, b))
