N = int(input())
a = [0] + list(map(int, input().split()))
ans = [0] * (N + 1)
an = []
for i in range(N, 0, -1):
	if sum(ans[i * 2 :: i]) % 2 != a[i]:
		ans[i] = 1
		an.append(i)
print(len(an))
Ans = [str(x) for x in an]
print(' '.join(Ans))