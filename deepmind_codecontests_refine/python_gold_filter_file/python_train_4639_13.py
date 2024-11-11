from math import sqrt
x, y = map(int, input().split())
M = float('inf')
for i in range(int(input())):
    u,k,v = map(int, input().split())
    # x = vt == > t = x/v
    xx = sqrt((x-u)**2 + (y-k)**2 )
    t = xx/v
    
    M = min(M, t)
print(M)