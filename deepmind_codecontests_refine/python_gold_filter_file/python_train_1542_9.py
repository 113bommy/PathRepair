n = int(input())
a = list(map(int, input().split()))
b = [0 for _ in range(n)]
for i in range(n-1, -1, -1):
	tmp = 0
	for j in range(2*(i+1)-1, n, i+1):
		tmp ^= b[j]
	b[i] = a[i]^tmp
ans = [i+1 for i in range(n) if b[i]]
print(len(ans))
print(*ans)