import sys
input = sys.stdin.readline
I = lambda : list(map(int,input().split()))

n,t=I()
l=I()
s=sum(l)
an=(t//s)*n
t=t%s;i=0;mi=min(l)
while t>=mi:
	c=k=i=0
	while i<n:
		if c+l[i]<=t:
			k+=1
			c+=l[i]
		i+=1
	if c==0:
		break
	an+=(t//c)*k
	t=t%c
print(an)