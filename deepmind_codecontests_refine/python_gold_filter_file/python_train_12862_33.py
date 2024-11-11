n = int(input())
L = []
c = 0
for i in range(n): L.append(input())
for i in range(n):
    if 'OO' in L[i]:
        L[i] = L[i].replace('OO', '++', 1)
        c += 1
        break
if c > 0:
    print('YES')
    for i in L: print(i)
else: print('NO')

