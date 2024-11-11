import math
k,n,s,p=list(map(int,(input().split())))
t=math.ceil(n/s)
t=t*k
print( math.ceil(t/p) )
