n = int(input())
a = sorted(list(map(int, input().split())), reverse=True)
ans = a[0]
for i in range(2, n):
	ans += a[i//2]
print(ans)