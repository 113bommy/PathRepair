n=int(input())
arr=list(map(int,input().split()))
arr.sort()
x=arr[-1]
flag=1
#print(arr)
if n==2:
	print(arr[0],arr[1])
else:
	for i in range(n-2,-1,-1):
		if x%arr[i]!=0:
			y=arr[i]
			flag=0
			break
	if flag:
		for i in range(n-1,0,-1):
			if arr[i]==arr[i-1]:
				y=arr[i]
				break
	print(x,y)