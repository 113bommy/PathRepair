
def getAns(n1,n2,k1,k2):
	x = 0
	y = 0
	if dp[n1][n2][k1][k2] != -1: return dp[n1][n2][k1][k2]
	if (n1+n2)==0: return 1
	if (n1>0 and k1>0): x = getAns(n1-1,n2,k1-1,b)
	if (n2>0 and k2>0): y = getAns(n1,n2-1,a,k2-1)
	dp[n1][n2][k1][k2] = (x+y)
	return dp[n1][n2][k1][k2]
	

n1,n2,k1,k2 = map(int,input().split())  
a = k1
b = k2
dp = [[[[-1 for i in range(k2+1)] for j in range(k1+1)] for k in range(n2+1)] for l in range(n1+1)]
# dp = [[[[-1]*(k2+1)]*(k1+1)]*(n2+1)]*(n1+1)
# print(dp)
ans = getAns(n1,n2,k1,k2)
print(ans%(10**8)) 