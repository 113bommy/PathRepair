from math import *
t = int(input())
m = []
n = []
for i in range(t):
    n = input()
    x = list(map(int, input().split()))
    m.append(x)

for i in range(t):
    k = []
    for j in range(len(m[i])):
        k.append(floor(m[i][j]/abs(m[i][j])))
    sum = 0
    tmp = m[i][0]
    for j in range(len(m[i])-1):
        if k[j] == k[j+1] and m[i][j+1] > tmp:
            tmp = m[i][j+1]
        if k[j+1] != k[j]:
            sum = sum + tmp
            tmp = m[i][j+1]
    sum = sum + tmp
    print(sum)

