from sys import stdin,stdout
import math
x,y=input().split()
x=int(x)
y=int(y)
f3=y-x
ans=0
n=int(input())
if n>3:
	k=n%3
	t=int(n/3)
	if k==0:
		if t%2==0:
			ans=-f3
		else:
		 ans=f3
	elif k==1:
		if t%2==0:
			ans=x
		else:
		 ans=-x
	else:
		if t%2==0:
			ans=y
		else:
		 ans=-y
else:
	if n==1:
		ans=x
	elif n==2:
		ans=y
	else:
	 ans=f3
while ans<0:
	ans=ans+1000000007
else:
 ans=ans%1000000007
print(ans)