t=int(input())
p=[]
for i in range(t):
	j=list(map(int,input().split()))
	p.append(j)
def minx(n,a,b):
	o=65
	ans=""
	while len(ans)<=n:
		o=65
		for i in range(b):
			ans+=chr(o)
			if len(ans)>=n:
				break
			o+=1
	return ans[:-1]
		
for i in range(t):
	y=minx(p[i][0],p[i][1],p[i][2])
	print(y.lower())