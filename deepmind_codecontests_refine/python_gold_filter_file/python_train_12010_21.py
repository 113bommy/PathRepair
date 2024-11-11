import sys
import math
  
n = int(sys.stdin.readline())
an = [int(x) for x in (sys.stdin.readline()).split()]

minv = 101
minv2 = 101

for i in range(n):
    if(an[i] < minv):
        minv2 = minv
        minv = an[i]
        
    if(an[i] < minv2 and an[i] > minv):
        minv2 = an[i]

if(minv2 == 101):
    print("NO")
else:        
    print(minv2)

