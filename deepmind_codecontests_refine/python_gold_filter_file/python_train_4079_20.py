for _ in range(int(input())):
    n = int(input())
    l = []
    r = []
    min_x = int(-10e4)
    min_y = int(-10e4)
    max_x = int(10e4)
    max_y = int(10e4)

    for i in range(n):
        z = list(map(int, input().split(" ")))
        r.append(z)
        if z[2:] != [1, 1, 1, 1]:
            l.append(z)
            if not z[2]:
                min_x = max(min_x, z[0])
            if not z[3]:
                max_y = min(max_y, z[1])
            if not z[4]:
                max_x = min(max_x, z[0])
            if not z[5]:
                min_y = max(min_y, z[1])
    if not l:
        print(1, r[0][0], r[0][1])
    else:
        ans = 1
        if min_x > max_x:
            ans = 0
        if max_y < min_y:
            ans = 0
        if ans:
            print(1, min_x, min_y)
        else:
            print(0)
        # print(max_x, min_x, max_y, min_y)
        # print(x_max, x_min, y_max, y_min)