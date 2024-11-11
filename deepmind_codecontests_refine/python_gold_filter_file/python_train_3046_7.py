t= int(input())
for i in range(t):
	n,k = map(int,input().split())
	a= list(map(int,input().split()))
	arr=[]
	for j in range(n):
		r=a[j]%k
		if r==0:
			arr.append(0)
		else:
			arr.append(k-r)
	j=0
	x=0
	count=0
	sme =0
	arr.sort()
	while (j<len(arr) and arr[j]==0):
		j+=1
	while(j<len(arr)):
		if (j<len(arr) and x<arr[j]):
			# print(x,arr[j])
			# count =count+(arr[j]-x)
			x=arr[j]
		while(j<len(arr) and x==arr[j]):
			sme+=1
			j+=1
		if (sme!=0):
			# print(x,sme,arr)
			
			max_x=x+1+(sme-1)*k
			x+=1
			if (max_x>count):
				count=max_x
			# print(count)
		sme=0
		
	print(count)
	

