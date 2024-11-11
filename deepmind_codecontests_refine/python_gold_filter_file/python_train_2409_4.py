n=int(input())
a=list(map(int,input().split()))
m=max(a)
"""
for i in range(m-1,-1,-1):
	if a[i]!=a[m]:
		break
	l-=1
for i in range(m+1,n):
	if a[i]!=a[m]:
		break
	r+=1
print(r-l)
"""
ma=0
l=0
for i in range(n):
	if  a[i]==m:
		l+=1
	else:
		ma=max(ma,l)
		l=0
print(max(ma,l))
