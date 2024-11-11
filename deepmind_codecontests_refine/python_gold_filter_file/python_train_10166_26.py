p,y = map(int,input().split())
for x in range(y,p,-1):
	if all(x%i for i in range(2,min(int(x**.5),p)+1)):
		#even if one devides it completely then not possible to sit
		#if nothing devides then it's sitable
		#factors repeat after reachin midway(sqrt)
		print(x)
		exit()
print(-1)