import math
n = int(input())
A = [int(x) for x in input().split()]
m = math.ceil(sum(A)/2)
p = 0
for i, a in enumerate(A):
    p += a
    if p >= m:
        print(i+1)
        break
    
