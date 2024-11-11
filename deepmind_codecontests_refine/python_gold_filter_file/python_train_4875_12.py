n,m=map(int,input().split())
mx =[-1 for i in range(0,n)]
for z in range(0,m):
  a,b=map(int,input().split())
  mx[b-1]=max(mx[b-1],a-1)
cut=-1
cn=0
for z in range(0,n):
	if cut<mx[z]:
		cut=z-1
		cn=cn+1
print(cn)