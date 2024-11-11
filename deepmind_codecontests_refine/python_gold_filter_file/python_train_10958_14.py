def solve(arr1,arr2):
	ans=2*min(arr1[2],arr2[1])

	temp=max(0,min(arr1[2],arr2[1]))
	arr1[2]-=temp
	arr2[1]-=temp
	# print(temp)

	temp=max(0,min(arr1[2],arr2[2]))
	arr1[2]-=temp
	arr2[2]-=temp
	# print(temp)

	temp=max(0,min(arr1[2],arr2[0]))
	arr1[2]-=temp
	arr2[0]-=temp
	# print(temp)

	temp=max(0,min(arr1[0],arr2[2]))
	arr1[0]-=temp
	arr2[2]-=temp
	# print(temp)

	temp=max(0,min(arr1[0],arr2[1]))
	arr1[0]-=temp
	arr2[1]-=temp
	# print(temp)

	temp=max(0,min(arr1[0],arr2[0]))
	arr1[0]-=temp
	arr2[0]-=temp
	# print(temp)

	temp=max(0,min(arr1[1],arr2[1]))
	arr1[1]-=temp
	arr2[1]-=temp
	# print(temp)

	temp=max(0,min(arr1[1],arr2[0]))
	arr1[1]-=temp
	arr2[0]-=temp
	# print(temp)

	# print(arr1)
	# print(arr2)


	ans-=2*arr1[1]

	print(ans)




t=int(input())
for _  in range(t):
	arr1= list(map(int,input().split()))
	arr2=list(map(int,input().split()))
	solve(arr1,arr2)
