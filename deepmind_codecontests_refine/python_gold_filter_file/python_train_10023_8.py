t = int(input())
for i in range(t):
    temp = [int(x) for x in input().split()]
    n = temp[0]
    m = temp[1]
    s = []
    for j in range(2*n):
        s.append([int(x) for x in input().split()])
    if m == 1:
        print('NO')
    elif m == 2:
        bool = True
        for j in range(0, 2*n, 2):
            if s[j][1] == s[j+1][0]:
                bool = False
                print('YES')
                break
        if bool:
            print('NO')
    else:
        bool = True
        for j in range(0, 2*n, 2):
            if m % 2 == 0 and s[j][1] == s[j+1][0]:
                bool = False
                print('YES')
                break
        if bool:
            print('NO')
