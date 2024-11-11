n,k = map(int, input().split())
way=input()

a= way.find('G')
b=way.find('T')
f=1
if (b-a)%k==0:
	
	m=(b-a)/k
	if m>0:
		while way[a+k*f]=='.':
			f+=1
		if f==m:
			print('YES')
		else:
			print('NO')
	if m<0:
		while way[a-k*f]=='.':
			f+=1
		if f==abs(m):
			print('YES')
		else:
			print('NO')
		
			
		
#	print(a,b)
else:
	print('NO')