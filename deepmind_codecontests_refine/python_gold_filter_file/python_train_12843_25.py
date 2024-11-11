n, k = map(int, input().split())
a = list(map(str, input().split()))
sum = 0
for i in a:
	if i.count('4')+i.count('7') <= k:
		sum += 1
print(sum)