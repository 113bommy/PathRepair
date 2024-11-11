from math import sqrt
n = int(input())
m = []
for i in range(n):
    m.append(list(map(int,input().split())))
sq = [0]*n
for i in range(n):
    if i == 1:
        sq[i] = m[i][0]*m[i][2]/m[0][2]
    elif i == 2:
        sq[i] = m[i][0]*m[i][1]/m[0][1]
    else:
        sq[i] = (m[i][1]*m[i][2])/m[1][2]
for x in sq:
    print(int(sqrt(x)),end=' ')