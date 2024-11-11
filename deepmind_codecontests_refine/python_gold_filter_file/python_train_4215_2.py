n = int(input())
s = [input() for i in range(n)]
m = [[0] * 26 for i in range(26)]
f = lambda x: ord(x) - ord('a')
for i in range(n - 1):
	for ch1, ch2 in zip(s[i], s[i + 1]):
		if ch1 != ch2:
			m[f(ch1)][f(ch2)] = 1
			break
	else:
		if len(s[i]) > len(s[i + 1]):
			print('Impossible')
			exit()
indeg = [sum(m[j][i] for j in range(26)) for i in range(26)]
added = [0] * 26
ans = []
while 1:
	for i in range(26):
		if indeg[i] == 0 and not added[i]:
			ans.append(chr(i + ord('a')))
			added[i] = 1
			for j in range(26):
				if m[i][j]:
					m[i][j] = 0
					indeg[j] -= 1
			break
	else:
		break
if any(indeg):
	print('Impossible')
	exit()
print(''.join(ans))

