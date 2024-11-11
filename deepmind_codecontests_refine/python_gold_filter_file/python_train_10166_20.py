p,y=map(int,input().split())



j=y
ans=-1
t=True
while j>p and t:
	for i in range(2,min(int(j**0.5),p)+1):
		if j%i==0:
			break
	else:
		t=False
		ans=j
	j-=1

print(ans)