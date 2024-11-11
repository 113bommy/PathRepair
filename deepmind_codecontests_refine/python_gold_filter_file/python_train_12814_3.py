def find(i):
	a = t[i]
	while i != n and s[i] != a:
		i += 1
	if i == n:
		print(-1)
		raise SystemExit()
	return i


n = int(input())
s = [i for i in input()]
t = [i for i in input()]
ans = []
for i in range(n):
	it = find(i)
	while it != i:
		s[it], s[it - 1] = s[it - 1], s[it]
		ans.append(it)
		it -= 1
print(len(ans))
print(*ans)
