n = int(input())
l = list(map(int, input().split()))
chest = 0
bicep = 0
back = 0

for i in range(len(l)):
    if i % 3 == 0:
        chest += l[i]
    elif i % 3 == 1:
        bicep += l[i]
    else: 
        back += l[i]

if max(chest, bicep, back ) == chest:
    print('chest')
if max(chest, bicep, back ) == bicep:
    print('biceps')
if max(chest, bicep, back ) == back:
    print('back')
