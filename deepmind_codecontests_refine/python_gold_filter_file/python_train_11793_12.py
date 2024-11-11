import math
n = input().split()
R = int(n[1])
r = int(n[2])
n = int(n[0])
res = 'YES'
if r * 2 > R:
    res = 'NO'
else:
    if r > round((R-r) * math.sin(2*math.pi/n/2),9):
        res = 'NO'
if r > R :
    res = 'NO'
if r <= R and n==1:
    res = "YES"

print(res)