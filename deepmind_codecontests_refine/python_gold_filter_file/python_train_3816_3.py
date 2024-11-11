n, m = map(int, input().split())
s = []
ok = 1
for i in range(n):
	a = input()
	s.append(a)
for i in range(n):
	for j in range(m):
		if s[i][j] == 'S':
			if i-1 >= 0 and s[i-1][j] == 'W':
				ok = 0
			if j-1 >= 0 and s[i][j-1] == 'W':
				ok = 0
			if i+1 < n and s[i+1][j] == 'W':
				ok = 0
			if j+1 < m and s[i][j+1] == 'W':
				ok = 0
if ok == 0:
	print("No")
else:
	print("Yes")
	for i in range(n):
		ans = ""
		for j in range(m):
			if s[i][j] == '.':
				ans += 'D'
			else:
				ans += s[i][j]
		print(ans)