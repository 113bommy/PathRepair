import math
r,d = map(int,input().split())
n = int(input())
ans = 0
for i in range(n):
	x,y,rad = map(int,input().split())
	s = math.sqrt(x**2+y**2)
	if(r-d+rad<=s<=r-rad):
		ans+=1
print(ans)