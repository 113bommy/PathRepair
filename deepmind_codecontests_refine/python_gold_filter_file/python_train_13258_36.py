s,n=map(int,input().split())
a=[]
c=0
for i in range(n):
	a.append([int(i) for i in input().split()])
a=sorted(a,key=lambda x:x[0])
for i in range(n):
		if(s>a[i][0]):
			s=s+a[i][1]
		else:
			c=1
			print("NO")
			break
if(c==0):
	print("YES")	