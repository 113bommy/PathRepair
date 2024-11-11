import math
a,b=map(int,input().split())
if a==1 or b==1:
  k=1
else:
	k=math.ceil((a*b)/2)
print(k)
