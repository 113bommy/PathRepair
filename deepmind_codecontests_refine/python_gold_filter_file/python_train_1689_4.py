for i in range(int(input())):
    p = sorted(input())
    p1 = input()
    f = True
    if len(p) > len(p1):
        print('NO')
        continue
    for i in range(len(p1) - len(p) + 1):
        if sorted(p1[i: i + len(p)]) == p:
            print('YES')
            f = False
            break
    if f:
        print('NO')
