from math import sqrt
s='aeuoi'
n=int(input());f=l=0
for i in range(5,round(sqrt(n))+1):
	if n%i==0 and 5<=n//i:f=i;l=n//i;break
if min(f,l)<5:print(-1)
else:
	r=r1=s*(f//5)+s[:f%5]
	for i in range(l-1):
		r1=r1[1:]+r1[:1]
		r+=r1
	print(r)