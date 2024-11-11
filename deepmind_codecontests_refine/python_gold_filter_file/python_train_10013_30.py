b = int(input())
g = int(input())
n = int(input())

ans = set()

for i in range(b + 1):
	if 0 <= n - i <= g:
		ans.add((i, n - i))


for i in range(g + 1):
	if 0 <= n - i <= b:
		ans.add((n - i, i))

print(len(ans))