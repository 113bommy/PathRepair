from copy import deepcopy

def f(n, m):
    return abs(n - m)

n = int(input())
mas = []
L = 0
R = 0
for i in range(n):
    l, r = map(int, input().split())
    mas.append((l, r))
    L += l
    R += r
sum = f(L, R)
old = deepcopy(sum)
new = deepcopy(old)
#print(L, R)
for i in range(n):
    L -= mas[i][0]
    R -= mas[i][1]
    L += mas[i][1]
    R += mas[i][0]
    #print(L, R)
    if f(L, R) > new:
        ans = i
        new = f(L, R)
    L -= mas[i][1]
    R -= mas[i][0]
    L += mas[i][0]
    R += mas[i][1]
if new - old == 0:
    print(0)
else:
    print(ans + 1)