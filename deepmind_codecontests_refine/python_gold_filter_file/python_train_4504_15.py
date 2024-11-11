itr=int(input())

for _ in range(itr):
	val=input().split()
	arr=[]
	loop= True
	for _ in range(int(val[0])):
		temp=list(map(int,input().split()))
		arr.append(temp)
		
	for i in range(int(val[0])):
			
		for j in range(int(val[1])):
			if i in [0,int(val[0])-1] and j in [0,int(val[1])-1]:
				if arr[i][j]>2:
					print('NO')
					loop= False
					
					break
				
				else:
					arr[i][j]=2
			elif (i>0 and i< int(val[0])-1 ) and (j>0 and j < int(val[1])-1):
				if arr[i][j]>4:
					print('NO')
					loop=False
					break
				else:
					arr[i][j]=4
				
			else:
				if arr[i][j]>3:
					print("NO")
					loop=False
					break
				else:
					arr[i][j]=3
		if loop==False:
			break
		
	if loop==False:
		continue
	print('YES')
	for x in range(int(val[0])):
		print(' '.join(map(str,arr[x])))
		



