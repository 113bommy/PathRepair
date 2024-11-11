w = int(input())
a = [[]]*w
b = [[]]*w
for i in range(w):
    a[i] = list(map(int,input().split()))
    b[i] = [0]*w
for i in range(w):
    for j in range(w):
        if i < j:
            ac = (a[i][j] + a[j][i]) / 2
            b[j][i] = ac - a[i][j]
            b[i][j] = -1 * b[j][i]
            a[i][j] = a[j][i] = ac
for i in range(w):
    for j in range(w):
        print('%.8f'%a[i][j],end=' ')
    print('')
for i in range(w):
    for j in range(w):
        print('%.8f'%b[i][j],end=' ')
    print('')