import sys
n, k = map(int, sys.stdin.readline().split())
a = list(sys.stdin.readline().rstrip())
a1 = []
a2 = []
for i in range(n):
    a1.append(a[i])
    a2.append(a[i])
if n == 1 and k != 0:
    print(0)
elif k == 0:
    for i in a:
        print(i, end='')
else:
    cnt = 0
    if a1[0] == '1':
        for i in range(1, n):
            if cnt == k:
                break
            if a[i] == '0':
                continue
            else:
                cnt += 1
                a1[i] = '0'
    else:
        a1[0] = '1'
        for i in range(1, n):
            if cnt == k - 1:
                break
            if a[i] == '0':
                continue
            else:
                cnt += 1
                a1[i] = '0'
    cnt = 0
    for i in range(n - 1, -1, -1):
        if cnt == k:
            break
        if a[i] == '0':
            continue
        else:
            if i != 0:
                cnt += 1
                a2[i] = '0'
    flag = -1
    for i in range(n):
        if int(a1[i]) < int(a2[i]):
            flag = 1
            break
        elif int(a1[i]) > int(a2[i]):
            flag = 2
            break
    if flag == 1:
        for i in a1:
            print(i, end='')
    else:
        for i in a2:
            print(i, end='')