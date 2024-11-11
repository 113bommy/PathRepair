import math
x,y,z,t1,t2,t3=map(int,input().split())
aa=(abs(x-y))*t1
bb=(abs(x-z))*t2
bb+=(3*t3)
bb+=((abs(x-y))*t2)
if(aa>=bb):
	print("YES")
else:
	print("NO")