from collections import*
n,*a=map(int,open(0).read().split())
C=Counter(a)
r=0
for x in sorted(a)[::-1]:
	if C[x]>0:y=1<<x.bit_length();C[x]-=1;r+=C[y-x]>0;C[y-x]-=1
print(r)