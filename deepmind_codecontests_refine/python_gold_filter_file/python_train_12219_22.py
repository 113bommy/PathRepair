n = int(input())
a = [int(i) for i in input().split()]
chest = 0
biceps = 0
back = 0
for i in range(0, len(a), 3):
    chest += a[i]
for i in range(1, len(a), 3):
    biceps += a[i]
for i in range(2, len(a), 3):
    back += a[i]
res = max(chest, biceps, back)
if chest > biceps and chest > back:
    print('chest')
elif biceps > chest and biceps > back:
    print('biceps')
else:
    print('back')