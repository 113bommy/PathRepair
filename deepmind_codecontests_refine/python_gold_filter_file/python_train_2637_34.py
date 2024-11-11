import math
n = int(input())
b = list(map(int, input().split()))


d = []


for i in range (4):
    s = 0
    for j in range (len(b)):
        if b[j] == 1 + i:
            s += 1
    d.append(s)
k = d[3]

if d[2] > d[0] and d[0] != 0:
    k += abs(d[2] - d[0])
    k += d[2] - abs(d[2] - d[0])
    k += math.ceil(d[1] / 2)
elif d[2] < d[0] and d[2] != 0:
    k += d[0] - abs(d[2] - d[0])
    k += math.ceil((d[1]*2 + abs(d[2] - d[0])) / 4)
elif d[2] == d[0]:
    k += d[0]
    k += math.ceil(d[1] / 2)
elif d[2] == 0:
    k += math.ceil((d[1]*2 + d[0]) / 4)
elif d[0] == 0:
    k += d[2]
    k += math.ceil(d[1] / 2)


print(k)