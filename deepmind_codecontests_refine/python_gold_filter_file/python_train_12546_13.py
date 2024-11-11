n = input()
arr = list(map(int,input().split()))
odd = []
even = []
for x in arr:
	if x%2 == 1:
		odd.append(x);
	else:
		even.append(x)
odd.sort()
sum1 = sum(odd)
sum1 = sum1 + sum(even)
if sum1%2==1:
	sum1 = sum1 - odd[0]
print(sum1)