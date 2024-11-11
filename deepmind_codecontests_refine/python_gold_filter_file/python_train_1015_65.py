import sys
input=sys.stdin.readline
N,k=map(int,input().split())
n=300_003
def update(i,x):#A[i]=x
	now=2**deep+i
	seg[now-1]=x
	while now>1:
		now//=2
		seg[now-1]=min(seg[now*2-1],seg[now*2])
def minimum(x,y):#A[x]からA[y]の最小値	
	s=inf
	l=x+2**deep
	r=y+2**deep+1
	while l<r:
		if l%2==1:
			s=min(s,seg[l-1])
			l+=1
		if r%2==1:
			r-=1
			s=min(s,seg[r-1])
		l//=2
		r//=2
	return s
inf=0
deep=(n-1).bit_length()
seg=[inf]*(2**deep*2-1)
for i in range(N):
	a=int(input())
	x=max(a-k,0)
	y=min(a+k,n)
	update(a,minimum(x,y)-1)
print(-minimum(0,n-1))
