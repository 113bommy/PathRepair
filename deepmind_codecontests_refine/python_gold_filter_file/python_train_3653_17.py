a, b, x = (int(x) for x in input().split())
flag = True
if a > b and x % 2 == 0:
    for i in range(x):
        if flag:
            print(0,end='')
            flag = False
        else:
            print(1,end='')
            flag = True
    for i in range(b - x // 2):
        print(1,end='')
    for i in range(a - x // 2):
        print(0,end = '')

if a > b and x % 2 != 0:
    for i in range(x-1):
        if flag:
            print(0,end='')
            flag = False
        else:
            print(1,end='')
            flag = True
    for i in range(a - x // 2):
        print(0,end='')
    for i in range(b - x // 2):
        print(1,end = '')

if a <= b and x % 2 == 0:
    for i in range(x):
        if flag:
            print(1,end='')
            flag = False
        else:
            print(0,end='')
            flag = True
    for i in range(a - x // 2):
        print(0,end='')
    for i in range(b - x // 2):
        print(1,end = '')

if a <= b and x % 2 != 0:
    for i in range(x-1):
        if flag:
            print(1,end='')
            flag = False
        else:
            print(0,end='')
            flag = True
    for i in range(b - x // 2):
        print(1,end='')
    for i in range(a - x // 2):
        print(0,end = '')
