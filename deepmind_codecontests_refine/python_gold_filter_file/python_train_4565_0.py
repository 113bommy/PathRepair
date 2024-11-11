INF=10**18

A=list(map(lambda x:ord(x)-48,list(input())))
B=list(map(lambda x:ord(x)-48,list(input())))

fl=False

for i in B:
	fl|=i

if fl==False:
	for i in A:
		if i:
			print("-1")
			exit(0)
	print("0")
	exit(0)

n=len(A)

bi=[]

for i in range(n):
	bi.append([0,0,i])
	for j in range(n):
		if B[(i-j)%n]:
			bi[i][0]=-j
			break
	for j in range(n):
		if B[(i+j)%n]:
			bi[i][1]=j
			break

bi.sort()

ans=INF

def Update(d):
	q=[]
	nr=max(0,d)
	for i in range(n):
		x=bi[i][2]
		if A[x]!=B[(x+d)%n]:
			q.append(bi[i][:2])
	ans=INF
	for i in q:
		ans=min(ans,2*(nr-min(0,min(d,i[0])))-abs(d))
		nr=max(nr,i[1])
	ans=min(ans,2*(nr-min(0,d))-abs(d))+len(q)
	return ans

for i in range(-n,n):
	ans=min(ans,Update(i))

print(ans)
