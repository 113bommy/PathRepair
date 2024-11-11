n=int(input())
a=[int(x) for x in input().split()]
pre=[]
pre.append(a[0])
for i in range(1,n):
	pre.append(a[i]+pre[i-1])
q=int(input())
for z in range(q):
	x,y=[int(x) for x in input().split()]
	if x==1:
		s=pre[y-1]
	else:
		s=pre[y-1]-pre[x-2]

	print(s//10)

