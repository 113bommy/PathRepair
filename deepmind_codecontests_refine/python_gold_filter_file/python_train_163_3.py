n,k,p = map(int,input().split(" "))
a = [int(x) for x in input().split(" ")]
b = [int(x) for x in input().split(" ")]
a.sort()
b.sort()
result = []
for i in range(k):
	max_time = 0
	if k - i < n:
		break
	for ind in range(n):
		tem=0
		tem += abs(a[ind]-b[i+ind])
		tem += abs(b[i+ind]-p)
		if max_time < tem:
			max_time = tem
	result.append(max_time)
print(min(result))