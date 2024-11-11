from math import sqrt
from collections import deque

def sub(a, b):
    return [a[0] - b[0],a[1] - b[1]]

def cross(a, b):
    return  a[0] * b[1] - a[1] * b[0]

def ccw(a, b, c):
    x = sub(b, a)
    y = sub(c, a)
    return cross(x, y) > 0

n = int(input())
c = [list(map(int, input().split())) for i in range(n)]
c.sort(key=lambda x: (x[0], x[1]))
U = deque(c[:2])

for i in range(2, n):
    j = len(U)
    while j >= 2 and ccw(U[-1],U[-2],c[i]):
        U.pop()
        j -= 1
    U.append(c[i])

c = c[::-1]
L = deque(c[:2])

for i in range(2, n):
    j = len(L)
    while j >= 2 and ccw(L[-1], L[-2], c[i]):
        L.pop()
        j -= 1
    L.append(c[i])

ans = U
for i in range(1,len(L)-1):
    x, y = L[i]
    ans.append([x,y])

print(len(ans))
i = ans.index(sorted(ans, key=lambda x: (x[1],x[0]))[0])
ans = list(ans)
for x,y in ans[i:] + ans[:i]:
    print(x, y)
