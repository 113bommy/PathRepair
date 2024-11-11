I=input
n=int(I())-1
a=sorted(map(int,I().split()))
s=sum(a)
l=a[-1]
r=2*10**9
while l<r:
	m=(l+r)//2
	if m*n<s:l=m+1
	else:r=m
print(l)