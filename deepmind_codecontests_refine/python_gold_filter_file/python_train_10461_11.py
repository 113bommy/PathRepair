a = input().split(" ")
banana = int(a[0])
dollars = int(a[1])
want = int(a[2])
total = 0
i = 0
j = 1

while i < want:
	total += j * banana
	j += 1
	i += 1
if dollars > total:
	print("0")
else:
	print(total - dollars)