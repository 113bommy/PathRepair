l = list(map(int, input().split(' ')))
if (max((3*l[0]/10), (l[0] - l[0]/250*l[2])) > max((3*l[1]/10), (l[1] - l[1]/250*l[3]))):
    print('Misha')
elif (max((3*l[0]/10), (l[0] - l[0]/250*l[2])) < max((3*l[1]/10), (l[1] - l[1]/250*l[3]))):
    print('Vasya')
else: print('Tie')
