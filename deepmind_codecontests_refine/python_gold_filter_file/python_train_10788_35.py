n=int(input())
positive , negative = 0,0
for i in range(0,n):
	x,y=input().split(" ")
	x,y=int(x),int(y)
	if x>0:
		positive+=1
	else:
		negative+=1
if positive<2 or negative<2:
	print("Yes")
else:
	print("No")
	