from sys import stdin
input=lambda : stdin.readline().strip()
lin=lambda :list(map(int,input().split()))
iin=lambda :int(input())
main=lambda :map(int,input().split())
from math import ceil,sqrt,factorial,log
from collections import deque
from bisect import bisect_left
def gcd(a,b):
	a,b=max(a,b),min(a,b)
	while a%b!=0:
		a,b=b,a%b
	return b
mod=998244353
def solve():
	n=iin()
	l=lin()
	dp=[[0 for i in range(202)] for i in range(n+2)]
	z=[[] for i in range(202)]
	for i in range(n):
		z[l[i]].append(i)
		for j in range(201):
			dp[i][j]=dp[i-1][j]
		dp[i][l[i]]+=1
		# print(l[i])
	ans=0
	for i in range(1,201):
		t=len(z[i])
		ans=max(ans,t)
		for j in range(ceil(t//2)):
			x=z[i][j]
			y=z[i][t-j-1]
			m=0
			for k in range(1,201):
				if i!=k:
					m=max(m,dp[y][k]-dp[x][k])
			ans=max(ans,2*(j+1)+m)
	print(ans)
qwe=1	
qwe=int(input())
for _ in range(qwe):
	solve()