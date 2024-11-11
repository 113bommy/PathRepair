n,m=map(int,input().split())

men=[]

for i in range(n):
	x,y=map(int,input().split())
	men.append((y,x-1))

def Calc(lim):
	cnt=[0]*m
	vis=[False]*n
	for i in range(n):
		cnt[men[i][1]]+=1
	cost=0
	for i in range(n):
		if men[i][1]!=0 and cnt[men[i][1]]>=lim:
			cnt[men[i][1]]-=1
			cost+=men[i][0]
			vis[i]=True
			cnt[0]+=1
	
	for i in range(n):
		if cnt[0]<lim and vis[i] == False and men[i][1]!=0:
			cnt[0]+=1
			cost+=men[i][0]
	return cost

men.sort()

ans = 10**18

for i in range(n):
	ans=min(ans,Calc(i))

print(ans)
