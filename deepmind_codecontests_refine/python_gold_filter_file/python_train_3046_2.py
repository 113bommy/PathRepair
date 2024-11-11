import sys
from collections import defaultdict

I=sys.stdin.readline

ans=""

for _ in range(int(input())):
	n,k=map(int,I().split())
	arr=sorted(list(map(int,I().split())))
	d=defaultdict(int)
	tmp=0
	for i in arr:
		if i%k!=0:
			if d[i%k]!=0:
				d[i%k]+=1
				x=(k*d[i%k])-(i%k)
			else:
				d[i%k]+=1
				x=((i//k)+1)*k-i
			tmp=max(tmp,x+1)
	ans+=str(tmp)+"\n"

print(ans)
