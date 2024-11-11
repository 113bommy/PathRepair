n,k,a=map(int,input().split())
m=int(input())+1
x=list(map(int,input().split()))+[0]
l,r=0,m
while r-l>1:
	d=(l+r)//2
	y=sorted(x[:d])
	if sum((q-p)//(a+1) for p,q in zip([0]+y,y+[n+1]))>=k:l=d
	else:r=d
print(r%m-(r==m))

