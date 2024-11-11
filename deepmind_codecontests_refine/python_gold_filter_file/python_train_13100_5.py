from collections import*
n,*a=map(int,open(0).read().split())
r=[];s=[]
for k,v in Counter(a).items():
	if v>1:
		r+=[k]
	if v>3:
		s+=[k]
if len(r)<2 and len(s)<1:
	print(0)
	exit()
r+=[0,0]
s+=[0]
r.sort()
s.sort()
print(max(r[-1]*r[-2],s[-1]**2))