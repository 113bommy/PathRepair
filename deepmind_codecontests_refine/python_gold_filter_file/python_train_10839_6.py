import math
n = int(input())
M = [input().split() for i in range(n)]
J =[]


def jump(a, b, k):

    if k % 2 == 0:
        x = (k//2)*a - (k//2)*b
    else:
        x = math.floor(k/2)*a-math.floor(k/2)*b+a
    J.append(x)


for i in range(n):
    for j in range(3):
        M[i][j] = int(M[i][j])

for i in M:
    x = i[0]
    y = i[1]
    z = i[2]
    jump(x, y, z)

for i in J:
    print(int(i))
