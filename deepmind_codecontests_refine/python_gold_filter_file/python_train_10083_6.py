n, a, b = map(int, input().split())
x = list(map(int, input().split()))

diff = [x[i] - x[i-1] for i in range(1, n)]

res = 0
for d in diff:
	res += min(d * a, b)

print(res)