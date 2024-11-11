import math
N, H = list(map(int, input().split()))
maxA = 0
b = []
n = 0
for _ in range(N):
    ta, tb = list(map(int, input().split()))
    maxA = max(maxA, ta)
    b.append(tb)
 
b = list(filter(lambda x: x > maxA, b))
b.sort()

while H > 0 and b:
    H -= b.pop()
    n += 1
print(n + math.ceil(max(H,0)/maxA) )
