n = int(input())
a = list(map(int, input().split()))
for i in range(len(a)):
	if a[a[a[i] - 1] - 1] - 1 == i:
		print('YES')
		break
else:
	print("NO")