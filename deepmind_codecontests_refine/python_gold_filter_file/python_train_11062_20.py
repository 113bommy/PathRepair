def bitonic(arr,n):
	i = n-2
	while i>=0 and arr[i]>=arr[i+1]:
		i-=1
	if i==-1:
		return 0
	while i>=0 and arr[i]<=arr[i+1]:
		i-=1
	if i==-1:
		return 0
	else:
		return i+1
			
t = int(input())
for cases in range(t):
	n = int(input())
	arr = list(map(int,input().strip().split()))
	if n<3:
		print(0)
	else:
		print(bitonic(arr,n))
				