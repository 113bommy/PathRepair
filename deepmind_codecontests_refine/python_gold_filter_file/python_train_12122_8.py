n,m = map(int,input().split())
l = list(map(int,input().split()))
d,c = {},n+1
for i in range(m):
	if l[i]<c:
		for j in range(l[i],c):
			d[j]=l[i]
		c=l[i]
for i in range(n):
	print(d[i+1],end=' ')