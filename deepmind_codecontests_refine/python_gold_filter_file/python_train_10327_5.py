for _ in range(int(input())):
	n = int(input())
	s, t = input(), input()
	i, j, ans = -1, -1, 0
	for k in range(n):
		if s[k] != t[k]:
			if ans:
				j = k
			else:
				i = k
			ans += 1
	if ans == 2 and (t[i] == t[j] and s[j] == s[i]):
		print("Yes")
	else:
		print("No")
