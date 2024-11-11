n=int(input())
arr=[int(x) for x in input().split(" ")]
sum=(0)
for i in range(len(arr)):
	sum+=arr[i]
arr.sort(reverse=True)
temp=int(0)
count=int(1)
for i in range(len(arr)):
	temp+=arr[i]
	if(temp>sum-temp):
		break
	count+=1
print(count)