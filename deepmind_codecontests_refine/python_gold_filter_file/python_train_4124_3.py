import sys
n = int(input())
data = [int(x) for x in input().split()]
if len(data) > 1:
    flgVV = data[0] < data[1]
    flgVn = data[-2] > data[-1]
    if flgVV:
        i = 0
        while i < len(data) - 1 and data[i] < data[i + 1]:
            i += 1
        if i == len(data) - 1:
            print('YES')
            sys.exit()
        while i < len(data) - 1 and data[i] == data[i + 1]:
            i += 1
        if i == len(data) - 1 and not flgVn:
            print('YES')
            sys.exit()
        while flgVn and i < len(data) - 1 and data[i] > data[i + 1]:
            i += 1
        if i < len(data) - 1:
            print('NO')
            sys.exit()
        print('YES')
    else:
        i = 0
        while i < len(data) - 1 and data[i] == data[i + 1]:
            i += 1
        if i == len(data) - 1 and not flgVn:
            print('YES')
            sys.exit()
        while flgVn and i < len(data) - 1 and data[i] > data[i + 1]:
            i += 1
        if i < len(data) - 1:
            print('NO')
            sys.exit()
        print('YES')
else:
    print('YES')