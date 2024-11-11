from collections import Counter

for case in range(int(input())):
	n = int(input())
	arr = [int(a) for a in input().split()]
	ans = []
	rem = []
	if len(set(arr)) == 1:
		print("NO")
	else:
		print("YES")
		root = arr[0]
		for i in range(1,n):
			if arr[i] != root:
				ans.append((1, i+1))
				new = i+1
			else:
				rem.append(i+1)
		for i in rem:
			ans.append((new, i))
	for con in ans:
		print(*con)