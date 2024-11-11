n=int(input())
xyz=0
for i in range(n):
	str=input()
	if(str=="++X" or str=="X++"):
		xyz+=1
	elif(str=="--X" or str=="X--"):
		xyz-=1
print(xyz)
