import math
n=int(input())
arr=list(map(int,input().split()))
if n==1:
	print(1)
	exit()
oddsum=0
evensum=0
for i in range(n):
	if i%2==0:
		oddsum+=arr[i]
	else:
		evensum+=arr[i]
currodd=0
curreven=0
ans=0
for i in range(n):
	# print("xxx")
	# print(curreven,currodd)
	if i%2==0:
		odd=currodd+(evensum-curreven)
		even=curreven+(oddsum-currodd-arr[i])
		if even==odd:
			ans+=1
		# print(even,odd)
		currodd+=arr[i]
	else:
		even=currodd+(evensum-curreven-arr[i])
		odd=curreven+(oddsum-currodd)
		# print(even,odd)
		if even==odd:
			ans+=1
		curreven+=arr[i]
print(ans)