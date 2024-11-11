import math
n=int(input())

k=int(math.sqrt(2*n))

if (k*(k+1))/2 == n:
    print("YES")
    
else:
    print("NO")