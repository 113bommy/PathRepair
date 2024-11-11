n=int(input())
arr=[int(x) for x in input().split()]
s=sum(arr)

if n==1:
	if s&1:
		print(3)
	else:
		print(2)
elif n==2:
	if s&1:
		print(2)
	else:
		print(3)
elif n==3:
	if s&1:
		print(4)
	else:
		print(3)
else:
	if((n+1)-(s%(n+1))>=5):
		print(5)
	else:
		print(4)
