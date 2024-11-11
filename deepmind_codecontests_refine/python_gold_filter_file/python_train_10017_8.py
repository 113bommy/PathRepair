n=int(input())
f=list(map(int,input().strip().split()[:n]))
od=0
eve=0
for x in f:
	if x%2==0:
		eve+=1
	else:
		od+=1
if eve%2==0 and od%2==0:
	print(eve)
elif eve==0:
	print(od)
elif od==0:
	print(eve)
elif eve%2==0 or eve%2!=0:
	if od%2!=0:
		print(od)
	else:
		print(eve)