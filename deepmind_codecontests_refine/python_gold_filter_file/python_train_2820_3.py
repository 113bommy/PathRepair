import sys

zz=1
 
sys.setrecursionlimit(10**5)
if zz:
	input=sys.stdin.readline
else:	
	sys.stdin=open('input.txt', 'r')
	sys.stdout=open('all.txt','w')
di=[[-1,0],[1,0],[0,1],[0,-1]]

def fori(n):
	return [fi() for i in range(n)]	
def inc(d,c,x=1):
	d[c]=d[c]+x if c in d else x
def ii():
	return input().rstrip()	
def li():
	return [int(xx) for xx in input().split()]
def fli():
	return [float(x) for x in input().split()]	
def comp(a,b):
	if(a>b):
		return 2
	return 2 if a==b else 0		
def gi():	
	return [xx for xx in input().split()]
def gtc(tc,ans):
	print("Case #"+str(tc)+":",ans)	
def cil(n,m):
	return n//m+int(n%m>0)	
def fi():
	return int(input())
def pro(a): 
	return reduce(lambda a,b:a*b,a)		
def swap(a,i,j): 
	a[i],a[j]=a[j],a[i]	
def si():
	return list(input().rstrip())	
def mi():
	return 	map(int,input().split())			
def gh():
	sys.stdout.flush()
def isvalid(i,j,n,m):
	return 0<=i<n and 0<=j<m 
def bo(i):
	return ord(i)-ord('a')	
def graph(n,m):
	for i in range(m):
		x,y=mi()
		a[x].append(y)
		a[y].append(x)


t=1
uu=t
def ncr(n,r):
	if n<r or n==0:
		return 0
	if r==0:
		return 1
	return (fac[n]*invfac[r]*invfac[n-r])%mod	
while t>0:
	t-=1
	n=fi()
	a=li()
	mod=998244353
	dp=[0]*(n+1)
	fac=[1]*(n+1)
	invfac=[1]*(n+1)
	for i in range(1,n+1):
		fac[i]=(i*fac[i-1])%mod
		invfac[i]=pow(fac[i],mod-2,mod) 
	for i in range(n-1,-1,-1):	
		if a[i]>0:
			for j in range(min(n,i+a[i]+1),n):
				dp[i]=(dp[i]+dp[j]*ncr(j-i-1,a[i]))%mod
			dp[i]=(dp[i]+ncr(n-i-1,a[i]))%mod
			#print(i,dp[i])	
	print(sum(dp)%mod)		
							