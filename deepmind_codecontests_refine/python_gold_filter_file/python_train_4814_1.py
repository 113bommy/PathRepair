t = int(input()) 

for l in range(t):
	n,x = map(int,input().split()) 
	arr = list(map(int,input().split()))
	arr.sort() 
	# print(arr)
	ans = n
	sum = 0
	for i in range(n-1,-1,-1) :
		sum += arr[i]
		avg = sum / (n-i)
		if(avg < x) :
			ans = (n-i-1)
			break
	print(ans)