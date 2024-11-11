n=int(input())
count=1
arr=[None]*n
for i in range(n):
	arr[i]=input()
	if arr[i-1]==None:
		continue
	elif arr[i]!=arr[i-1]:
		count+=1
print(count)