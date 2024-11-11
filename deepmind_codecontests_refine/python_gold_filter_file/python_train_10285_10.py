import sys
read = sys.stdin.buffer.read
input = sys.stdin.readline
input = sys.stdin.buffer.readline


sys.setrecursionlimit(10**9)
from functools import lru_cache

def RD(): return sys.stdin.read()
def II(): return int(input())
def MI(): return map(int,input().split())
def MF(): return map(float,input().split())
def LI(): return list(map(int,input().split()))
def LF(): return list(map(float,input().split()))
def TI(): return tuple(map(int,input().split()))
# rstrip().decode('utf-8')

#

def main():
	mod=10**9+7
	n=II()
	G=[[] for _ in range(n+1)]
	p=[0]*(n+1)
	v=[0]*(n+1)


	for _ in range(n-1):
		a,b=MI()
		G[a].append(b)
		G[b].append(a)

	inv2=[1]*(n+1)
	t=pow(pow(2,n,mod),mod-2,mod)
	for i in range(n,-1,-1):
		inv2[i]=t
		t*=2
		t%=mod
	#print(inv2)

	def dfs(a):
		cnt=1
		for i in G[a]:
			if p[a]==i:
				continue
			else:
				p[i]=a
				cnt+=dfs(i)
		v[a]=cnt
		return cnt
	dfs(1)
	#print(v)

	def f(a):
		return (1-inv2[a])*(1-inv2[n-a])%mod

	ans=1-inv2[n]-n*inv2[1]
	for i in range(1,n+1):
		ans+=f(v[i])%mod
	print(ans%mod)



if __name__ == "__main__":
	main()