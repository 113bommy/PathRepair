from collections import deque
for i in range(int(input())):
	n,k=map(int,input().split())
	arr=list(map(int,input().split()))
	arr2=list(map(int,input().split()))
	arr.sort()
	arr2.sort()
	arr1=deque()
	for jj in arr:
		arr1.append(jj)
	ans=0
	for j in arr2:
		if j==1:
			ans+=arr1[-1]+arr1[-1]
			arr1.pop()
	for j in arr2[::-1]:
		if j>=2:
			ans+=arr1[0]
			arr1.popleft()
			ans+=arr1[-1]
			arr1.pop()
			while j>2:
				arr1.popleft()
				j-=1
	print(ans)