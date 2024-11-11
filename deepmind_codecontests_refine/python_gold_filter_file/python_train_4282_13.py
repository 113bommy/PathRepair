import math
n,s = [int(x) for x in input().split()]
v = [int(x) for x in input().split()]

if(sum(v) < s):
    print(-1)
    exit()
    
m = min(v)
for i in range(len(v)):
    s -= v[i] - m

if(s <= 0):
    print(m)
else:
    print(m - (s + n - 1) // n)