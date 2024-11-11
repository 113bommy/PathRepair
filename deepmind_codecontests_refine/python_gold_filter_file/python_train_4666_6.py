ans = [0, 0, 0, 0]
for i in range(3):
	x = list(map(int, input().split()))
	for xi in x:
		ans[xi - 1] += 1
if sorted(ans) == [1, 1, 2, 2]:
	print("YES")
else:
	print("NO")
