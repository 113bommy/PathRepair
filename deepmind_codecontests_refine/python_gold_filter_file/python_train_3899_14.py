import sys
import math
  
n, v = [int(x) for x in (sys.stdin.readline()).split()]
k = [0] * 3002

for i in range(n):
    a, b = [int(x) for x in (sys.stdin.readline()).split()]
    k[a] += b
    
i = 1
res = 0
while(i <= 3001):
    val = 0
    if(k[i - 1] < v):
        val = k[i - 1]
        res += val 
        d = v - val
        if(k[i] < d):
            res += k[i]
            k[i] = 0
        else:
            res += d
            k[i] = k[i] - d
    else:
        res += v
     
    i += 1    
print(res)  