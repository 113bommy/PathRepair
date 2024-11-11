n=int(input())
array=[]
a=-1
for i in range(0,n):
	x=input()
	array.append(x)
for i in range(0,n):
	if "OO" in array[i]:
		array[i]=array[i].replace("OO","++",1)
		array.insert(0,"YES")
		break
	else:
		a+=1
if a!=n-1:
	for i in range(0,n+1):
		print(array[i])
else:
	print("NO")
	exit(0)