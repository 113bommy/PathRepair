from sys import *
n,k=input().split()
n=int(n);k=int(k)
kk=(1+k)*k//2
if n<kk:
	print(-1)
	exit(0)
def ans(g):
	if n<g*kk:return
	r=n-kk*g
	for _ in range(1,k):print(_*g,end=' ')
	print(k*g+r)
	exit(0)
for d in range(1,200000):
	if n%d==0:
		ans(n//d)
for d in range(200000,0,-1):
	if n%d==0:ans(d)
