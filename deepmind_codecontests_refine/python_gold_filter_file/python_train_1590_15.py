import math
n = int(input())
l = list(map(int,input().split()))
l.sort()
m = 1000000000000000
k = 1
s = 0
sq = int(math.sqrt(l[n-1]))
for i in range(sq+2,0,-1):
    s = 0
    k = 1
    for j in range(n):
        s = s + abs(l[j]-k)
        k = (k * (sq+3-i))
        if k>1000000000000000:
            break
    if m>=s:
        m = s
    else:
        break
print(m)