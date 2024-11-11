import math
n = int(input())
base = 'ROYGBIV'
add = 'BGYOR' 
ans = base

while len(ans) < 150:
    ans += ans[-4:]

print(ans[:n])
