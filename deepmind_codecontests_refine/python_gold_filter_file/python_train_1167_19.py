for q in range(int(input())):
    n = int(input())
    d = [tuple([int(j) for j in input().split()]) for i in range(n)]

    d.sort()
    bad = False
    for i in range(n-1):
        if d[i][0] > d[i+1][0] or d[i][1] > d[i+1][1]:
            bad = True
            break
    if bad:
        print("NO")
    else:
        print("YES")
        x, y = 0, 0
        for i in range(n):
            if d[i][0] > x:
                print('R'*(d[i][0] - x), end='')
                x = d[i][0]
            if d[i][1] > y:
                print('U'*(d[i][1] - y), end='')
                y = d[i][1]
        print()
            

            