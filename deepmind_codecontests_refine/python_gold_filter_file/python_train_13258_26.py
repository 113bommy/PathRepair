line = input()
s,n = [int(i) for i in line.split()]
dragon = []
for i in range(n):
    line = input()
    dragon.append([int(i) for i in line.split()])
dragon.sort()
live = True
for i in dragon:
    if s > i[0]:
        s += i[1]
    else:
        live = False
        break
if live:
    print('YES')
else:
    print('NO')
