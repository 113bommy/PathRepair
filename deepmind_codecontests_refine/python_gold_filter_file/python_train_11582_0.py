from sys import stdin
input=lambda : stdin.readline().strip()
from math import ceil,sqrt,factorial,gcd
def check(z):
	c=0
	for i in range(len(z)):
		if z[i]=='#':
			if c==0:
				c+=1
			else:
				if z[i-1]!='#':
					return False
	return True
n,m=map(int,input().split())
l=[]
emptyrow=0
emptycol=0
for i in range(n):
	l.append(list(input()))
	if l[i].count('#')==0:
		emptyrow+=1
	if check(l[i])==False:
		print(-1)
		exit()
for i in range(m):
	f=0
	z=[]
	for j in range(n):
		z.append(l[j][i])
		if l[j][i]=='.':
			f+=1
	if f==n:
		emptycol+=1
	if check(z)==False:
		print(-1)
		exit()
if (emptyrow>0 and emptycol>0) or (emptycol==0 and emptyrow==0):
	s=[[0 for i in range(m)] for i in range(n)]
	count=0
	connected=dict()
	z=[]
	for i in range(n):
		for j in range(m):
			if l[i][j]=='#':
				x=1
				connected[(i,j)]=[]
				if i>0 and l[i-1][j]=='#':
					connected[(i-1,j)].append((i,j))
					connected[(i,j)].append((i-1,j))
				else:
					x+=1
				if j>0 and l[i][j-1]=='#':
					connected[(i,j-1)].append((i,j))
					connected[(i,j)].append((i,j-1))
				else:
					x+=1
				if x==3:
					z.append((i,j))
	for i in z:
		if s[i[0]][i[1]]==0:
			stack=[i]
			count+=1
			while stack:
				a=stack.pop()
				for j in connected[a]:
					if s[j[0]][j[1]]==0:
						stack.append(j)
						s[j[0]][j[1]]=1
				s[a[0]][a[1]]=1
				del connected[a]
	print(count)
else:
	print(-1)



