import sys
input=sys.stdin.buffer.readline

arr1=list(map(int,input().split()))
arr2=list(map(int,input().split()))
arr3=list(map(int,input().split()))
ans=[]
temp=[]
s=arr1[0]+arr1[1]+arr2[0]
temp.append(s)
s=sum(arr1)+arr2[1]
temp.append(s)
s=arr1[1]+arr1[2]+arr2[2]
temp.append(s)
s=arr1[0]+arr2[0]+arr3[0]+arr2[1]
temp.append(s)
s=arr1[1]+sum(arr2)+arr3[1]
temp.append(s)
s=arr1[2]+arr2[2]+arr3[2]+arr2[1]
temp.append(s)
s=arr2[0]+arr3[0]+arr3[1]
temp.append(s)
s=sum(arr3)+arr2[1]
temp.append(s)
s=arr2[2]+arr3[2]+arr3[1]
temp.append(s)
count=0
for i in range(9):
	count+=1
	if temp[i]%2==0:
		print("1",end='')
	else:
		print("0",end='')
	if count%3==0:
		print()
