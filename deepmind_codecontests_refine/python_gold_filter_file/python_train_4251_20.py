import math
m,n=map(int,input().split())
k=int(math.sqrt(n))
ju=[False for i in range(k+1)]
da=[]
ki=2
co=-1
while ki<k+1:
	if n%ki==0:
		n//=ki
		if ju[ki]:
			da[co]+=1
		else:
			co+=1
			da.append(1)
			ju[ki]=True
	else:
		ki+=1
co+=1
ans=1
for i in range(co):
	si=da[i]
	dp=[[0 for i in range(si+1)] for j in range(m+1)]
	dp[0][0]=1
	for j in range(1,m+1):
		for k in range(si+1):
			for l in range(k+1):
				dp[j][k]=(dp[j-1][l]+dp[j][k])%(1000000007)
	ans=(ans*dp[m][si])%(1000000007)
if n>1:
	ans=((ans*m)%1000000007)
print(ans)
