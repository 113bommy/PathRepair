n = int(input())
a = list(map(int,input().split()))
aWithIndex = []
for i in range(n):
    aWithIndex.append((a[i],i))
aWithIndex.sort(key = lambda x: x[0])
aOrder = [-1] * n
for i in range(n):
    aOrder[aWithIndex[i][1]] = i
aOrderInverse = [-1] * n
for i in range(n):
    aOrderInverse[aOrder[i]] = i
result = []
for i in range(n):
    for j in range(aOrder[i] - 1, i - 1, -1):
        result.append(str(i + 1) + ' ' + str(aOrderInverse[j] + 1))
        tmp = aOrder[i]
        aOrder[i] = aOrder[aOrderInverse[j]]
        aOrder[aOrderInverse[j]] = tmp
    for j in range(n):
        aOrderInverse[aOrder[j]] = j
print(len(result))
if len(result) != 0:
    print('\n'.join(result))
