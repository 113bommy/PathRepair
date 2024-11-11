t=int(input())
for test in range(t):
	n=int(input())
	arr=[]
	for i in range(n):
		l,r=map(int,input().split())
		arr.append([l,r,i])
	arr=sorted(arr,key=lambda item:item[0])
	i=1
	ans=[0]*(n)
	ans[arr[0][2]]=1
	mm=arr[0][1]
	f=0
	while i<n:
		# print("f",f)
		mm=max(arr[i-1][1],mm)
		if arr[i][0]<=mm and f!=1:
			ans[arr[i][2]]=1
		else:
			f=1
			ans[arr[i][2]]=2
		i+=1
		# print('ji')


	if f==0:
		print(-1)
	else:
		for i in ans:
			print(i,end=" ")
		print()