h,n=map(int,input().split())
p=1<<(h-1)
i=r=0
n-=1
while h:
	r+=1
	if n>=p:j=1;n-=p
	else:j=0
	if j^i:r+=p+p-1
	else:i=1-i
	p>>=1
	h-=1
print(r)
