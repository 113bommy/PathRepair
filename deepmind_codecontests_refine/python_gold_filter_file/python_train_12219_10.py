n = int(input())
l = list(map(int, input().split()))
chest = 0
biceps = 0
back = 0
chest = l[::3]
biceps = l[1::3]
back = l[2::3]
chest = sum(chest)
biceps = sum(biceps)
back = sum(back)
if biceps > back and biceps > chest:
    print('biceps')
elif chest > biceps and chest > back:
    print('chest')
else:
    print('back')