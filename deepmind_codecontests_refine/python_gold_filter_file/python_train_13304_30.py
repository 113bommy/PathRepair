l,r=map(int,input().split( ))
p=2019
if r-l>=p:
	print(0)
else:
	tmp=p
	for i in range(l,r+1):
		for j in range(i+1,r+1):
			tmp=min(tmp,(i*j)%p)
	print(tmp)
