import math
t=int(input())
for i in range(t):
    n=int(input())
    if(n*n-4*n>=0):
        a=(n+math.sqrt(n*n-4*n))/2
        b=n-a
        print("Y %.9f %.9f"%(a,b))
    else:
        print("N")
