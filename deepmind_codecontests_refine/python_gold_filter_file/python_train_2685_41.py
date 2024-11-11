import sys
import fractions
sys.setrecursionlimit(10**9)

n,m=map(int,input().split())
alist=list(map(int,input().split()))
alist=list(set(alist))

n=len(alist)


def sks(n):
	global alist
	if n == 1:
		return alist[0]
	else:
		tmp=sks(n-1)
		return tmp*alist[n-1]//fractions.gcd(tmp,alist[n-1])

sk = sks(n)
gomi=sk//2

for a in alist:
	if (gomi-a//2)%a != 0:
		print(0)
		sys.exit()

print(int((m+gomi)//sk))

