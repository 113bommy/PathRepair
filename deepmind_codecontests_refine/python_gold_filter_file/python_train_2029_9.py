string = input()
nAB, nBA = string.count('AB'), string.count('BA')

if nAB == 0 or nBA == 0:
    print('NO')
    exit()

dBA, dAB = -2, -2
for i in range(nAB):
    dAB =string.find('AB',dAB+2)
    for j in range(nBA):
        dBA = string.find('BA',dBA+2)
        if abs(dBA - dAB) > 1:
            print('YES')
            exit()
    dBA = -2
print('NO')