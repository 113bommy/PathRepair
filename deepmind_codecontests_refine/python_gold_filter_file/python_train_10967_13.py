n, k =map(int,input().strip().split())
l1 = list(map(int, input().strip().split()))


n = 2 * n + 1

for d in range(1, n - 1, 2):
	if k == 0:
		break

	if l1[d]-1>l1[d-1] and l1[d] -1>l1[d+1]:
		l1[d] -= 1
		k -= 1
print(" ".join(str(x) for x in l1))