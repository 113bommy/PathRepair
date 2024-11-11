n=int(input())
p=[]
for i in range(n):
	x,y=map(int,input().split())
	p.append([x-1,y-1])
ans=[]
k=0
i=0
#print(p)
while 1:
	#print(i,p[i][0],p[i][1])
	#print(p[p[i][0]],p[p[i][1]])
	if p[i][0] in p[p[i][1]]:
		ans+=[i,p[i][1]]
		i = p[i][0]
	else:
		ans += [i,p[i][0]]
		i=p[i][1]
	#print(ans,i)
	k+=2
	if k>=n:
		break
#print(ans)
for i in range(n):
	print(ans[i]+1,end=" ")
