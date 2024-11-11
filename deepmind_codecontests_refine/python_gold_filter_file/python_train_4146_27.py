import math
n = int(input())
l = sorted(list(map(int,input().split())))
c = 0
b = {}
for i in range(len(l)):
    if l[i] in b:
        b[l[i]] += 1
    else:
        b[l[i]] = 1

for i in range(len(l) - 1, -1, -1):
    if  b[l[i]] == 0:
        continue
    t = l[i]
    b[l[i]] -= 1
    s = 2 ** math.floor(math.log2(t))
    st = 2*s - t 
    if l == []:
        break
    if st in b and b[st] > 0:
        b[2 * s - t] -= 1
        c += 1
print(c)