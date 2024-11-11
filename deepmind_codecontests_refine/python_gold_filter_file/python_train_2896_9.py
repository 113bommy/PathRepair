import copy
n, k = map(int, input().split())
B = list(map(int, input().split()))
A = []
for l in range(0, n):
	for r in range(l+1, n+1):
		A.append(sum(B[l:r]))
#print(A)
ans = 0
for i in range(41, -1, -1):
	tmp = []
	res = 0
	for a in A:
		if (a >> i) & 1 == 1:
			tmp.append(a)
			res += 1
	if res >= k:
		ans += 1 << i
		A = copy.copy(tmp)
print(ans)