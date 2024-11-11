n = int(input())
a = [int(i) for i in input().split()]
mn = 1000
sum = 0
for i in range(n):
	sum+=a[i]
	if a[i]%2 == 1 and a[i]<mn:
		mn = a[i]
if sum%2 == 1:
	print(sum)
elif sum%2 == 0 and mn == 1000:
	print(0)
else:
	print(sum-mn)
