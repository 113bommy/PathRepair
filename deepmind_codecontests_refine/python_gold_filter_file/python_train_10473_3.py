def f(a,o):
    return (a+1)*(o+1)*(a+o)//2
import math
m,b=[int(f)for f in input().split()]
top=0
for x in range(b+1):
    top=max(f(x,(b-x)*m),top)
print(top)
