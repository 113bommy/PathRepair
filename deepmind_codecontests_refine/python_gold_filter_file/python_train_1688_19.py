t = int(input())
for i in range(t):
    p = input()
    h = input()
    f = True
    for i in range(len(h) - len(p) + 1):
        if sorted(h[i: i + len(p)]) == sorted(p):
            print('YES')
            f = False
            break
    if f:
        print('NO')
