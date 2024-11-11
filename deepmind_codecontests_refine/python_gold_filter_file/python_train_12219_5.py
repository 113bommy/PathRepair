n = int(input())
a = [int(i) for i in input().split()]
chest = 0
biceps = 0
back = 0
if n >= 3:
    for i in range(0, n, 3):
        chest += a[i]
    for i in range(1, n, 3):
        biceps += a[i]
    for i in range(2, n, 3):
        back += a[i]
elif n == 2:
    for i in range(0, n + 1, 3):
        chest += a[i]
    for i in range(1, n + 1, 3):
        biceps += a[i]
elif n == 1:
    print('chest')
if chest > biceps and chest > back:
    print('chest')
elif biceps > chest and biceps > back:
    print('biceps')
elif back > biceps and back > chest:
    print('back')
