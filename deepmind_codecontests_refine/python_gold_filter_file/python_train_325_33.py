n, x, y = map(int, input().split())
s = list(input())
l1 = x
l2 = y
s = s[::-1]
ans = 0
sk = '0' * y + '1'
for i in range(y + 1):
	if sk[i] != s[i]:
		ans += 1
		s[i] = sk[i]
sk = sk + '0' * (x - y - 1) + '1'
for i in range(x):
	if sk[i] != s[i]:
		ans += 1
print(ans)
