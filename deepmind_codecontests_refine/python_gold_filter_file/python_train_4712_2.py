import sys
input=sys.stdin.readline
f=lambda :list(map(int, input().split()))
res=[]
for _ in range(int(input())):
	n, x=f()
	a=sorted(f(), reverse=True)
	c=1
	ans=0
	for i in a:
		if i*c>=x:
			ans+=1
			c=0
		c+=1
	res.append(ans)
print('\n'.join(map(str, res)))