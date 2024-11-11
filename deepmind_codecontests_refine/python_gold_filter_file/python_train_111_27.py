n=input()
n=int(n)
arr=[0 for i in range(n)]
arr=input().split()
for i in range(n):
	arr[i]=int(arr[i])
a=sum(arr)
k=max(arr)
while( ((n*k)-a) <=a):
	k=k+1
print(k)