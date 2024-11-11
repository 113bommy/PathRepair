import math
n,m=map(int,input().split())
sum=1
if(m-n>=5):
	print(0)
else:
	for i in range(n+1,m+1):
		sum*=i
	print(sum%10)
