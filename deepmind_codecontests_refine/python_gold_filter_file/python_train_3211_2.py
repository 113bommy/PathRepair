import math
N,Z,W=list(map(int,input().split()))
a=list(map(int,input().split()))
b=math.fabs(a[N-1]-W)
c=math.fabs(a[N-2]-a[N-1])
print(int(max(b,c)))