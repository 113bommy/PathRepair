n,x=map(int,input().split())
a=sorted(list(map(int,input().split())))
s=0
for i in range(n):
	if x>1:
		s+=a[i]*x
	else:
		s+=sum(a[i:])
		print(s)
		exit()
	x-=1
print(s)		
