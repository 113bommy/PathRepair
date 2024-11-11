n = int(input())
c = 0
from copy import copy, deepcopy
answer = [[0 for i in range(n)] for i in range(n)]
for i in range(n//2):
    a = list()
    for j in range(n):
        a.append(c)
        c += 1

    answer[i] = copy(a)
    answer[i + n//2] = copy(a)
for i in range(n):
    for j in range(n):
        if i<n//2:
            answer[i][j] = answer[i][j]*2
        else:
            answer[i][j] = answer[i][j]*2 + 1


print('\n'.join(map(lambda l: ' '.join(map(str, l)), answer)))