n=int(input())
arr=list(map(int,input().split()))
sm=sum(arr)
m=0
if n==1:
	print(1)
	exit()
for i in range(n):
	m+=arr[i]
	if m>=(sm+1)//2:
		print(i+1)
		exit()