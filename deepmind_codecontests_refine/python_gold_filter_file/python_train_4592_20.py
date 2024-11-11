import math
	
t=int(input())
for i in range(0,t):
	m,n=map(int,input().split())
	diff=m-n
	if(diff!=1):
		print("NO")
		continue
	s=m+n
	for j in range(2,int(math.sqrt(m+n))+1):
		if(s%j==0):
			print("NO")
			break
	else:	
		print("YES")	
	