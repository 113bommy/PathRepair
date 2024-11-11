import sys
input=sys.stdin.readline
I = lambda : list(map(int,input().split()))

def ans(ar,k):
	an = 0
	for i in range(len(ar)-k-1,-1,-k):
		an+=2*abs(ar[i])
	return an

t,=I()
for _ in range(t):
	n, k = I()
	l = sorted(I())
	ix = n
	for i in range(n):
		if l[i]>0:
			ix=i;break
	neg = l[:ix];pos = l[ix:]
	an = ans(neg[::-1],k)+ans(pos,k)
	if neg and pos:
		an += min(abs(neg[0]) + 2*pos[-1],pos[-1]+2*abs(neg[0]))
	elif pos:
		an+=pos[-1]
	elif neg:
		an+=(-neg[0])
	print(an)