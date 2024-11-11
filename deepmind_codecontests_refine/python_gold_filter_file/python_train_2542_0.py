import sys
import math

n = int(sys.stdin.readline())
xn = [int(x) for x in (sys.stdin.readline()).split()]



xn.sort()

k = [1]
res = 1
for i in xn[1:]:
    flag = False
    for t in range(res):    
        if(i >= k[t]):
            k[t] += 1
            flag = True
            break
    
    if(flag == False):
        res += 1
        k.append(1)
        
print(res)
        