from itertools import permutations, cycle
s = input()
n = len(s)
for p in permutations("RBYG", 4):
    flag = True
    d = {'R':0,'G':0,'B':0,'Y':0}
    for x, y in zip(s, cycle(p)):
        if x == '!':
            d[y] += 1
        elif x != y:
            flag = False
            break
    if flag:
        print(d['R'],d['B'],d['Y'],d['G'])
        break