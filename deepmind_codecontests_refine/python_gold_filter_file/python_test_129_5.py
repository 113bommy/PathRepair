import sys
from collections import Counter as cc
input=sys.stdin.readline
I = lambda : list(map(int,input().split()))

t,=I()
for _ in range(t):
	n, = I()
	l = sorted(I())
	an = 0
	pos = 1
	vis = [0]*n
	visi = [0]*(n+1)
	for i in range(n):
		if l[i]<=n and visi[l[i]]==0:
			visi[l[i]]=vis[i]=1

	lt = [i for i in range(1,n+1) if not visi[i]]
	st = [(l[i]-1)//2 for i in range(n) if not vis[i]]
	pos = all(lt[i]<=st[i] for i in range(len(st)))
	print(len(st) if pos else -1)