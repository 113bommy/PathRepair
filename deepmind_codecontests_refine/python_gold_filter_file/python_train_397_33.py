from collections import*
H,*A=open(0)
H,W,K=map(int,H.split())
*A,=map(list,A)
for i,a in enumerate(A):
	if'S'in a:j=a.index('S');Q=deque([(0,i,j)])
d=1e9
while Q:
	c,i,j=Q.popleft();d=min(d,i,j,H-i-1,W-j-1)
	if c<K:
		for h,w in((i+1,j),(i,j+1),(i-1,j),(i,j-1)):
			if H>h>-1<w<W and'.'==A[h][w]:A[h][w]=0;Q+=(c+1,h,w),
print(1--d//K)