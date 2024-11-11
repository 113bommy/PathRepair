n = int(input())
if n == 1:
	print("YES")
	exit()

nums = [int(i) for i in input().split()]

max = 0;
D = {}

for num in nums:
	if num not in D:
		D[num] = 0;
	D[num] += 1
	if D[num] > max:
		max = D[num]

mid = (n+1) // 2;
if max > mid:
	print("NO")
else:
	print("YES")
 

