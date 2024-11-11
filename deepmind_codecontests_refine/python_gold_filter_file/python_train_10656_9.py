n = int(input())
l = []
r = []
res = -1

for i in range(0, n):
    temp_n, temp_m = map(int, input().split())
    l.append(temp_n)
    r.append(temp_m)

leftMin = 99999999999
rightMax = 0

for i in range(0, n):
    leftMin = min(leftMin, l[i])
    rightMax = max(rightMax, r[i])

for i in range(0, n):
    if (leftMin == l[i] and rightMax == r[i]):
        res = i+1
        break

print(res)
