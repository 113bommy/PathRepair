import math
n=int(input())
arr=[]
for i in range(2,n+1):
	if n%i==0:
		cnt=0
		while n%i==0:
			cnt+=1
			n=n//i 
		arr.append([i,cnt])
# print(arr)
mul=0
mn=1
st=0
for i in range(len(arr)):
	mn=mn*arr[i][0]
	xx=int(math.log2(arr[i][1]))
	# print(xx,(1<<xx))
	if arr[i][1]>(1<<xx):
		xx+=1
	st=max(st,xx)
for i in range(len(arr)):
	if arr[i][1]<(1<<st):
		mul=1
print(mn,st+mul)