for _ in range(int(input())):
    n = int(input())
    path = []
    num = list(input())
    path.append(list(map(int, num)))
    num = list(input())
    path.append(list(map(int, num)))
    p = 0
    level =0
    for i in range(n):
        if path[level][i]==1 or path[level][i]==2:
            pass
        else:
            if (path[level^1][i] == 1 or path[level^1][i] == 2):
                p=1
                break
            else:
                level^=1
    # print(p,level,not level)
    if(p):
        print('NO')
    else:
        if level:
            print('YES')
        else:
            print('NO')

