s = input()
sub = input()
n1, n2 = len(s), len(sub)
ans = 0
i1, i2 = 0, 0
while i1 < n1:
	ist = i1 + 1
	while i1 < n1 and i2 < n2 and sub[i2] == s[i1]:
		if s[i1] == sub[0] and i1 > ist:
			ist = i1
		i1 += 1
		i2 += 1
	if i2 == n2:
		ans += 1
	else:
		i1 = ist
	i2 = 0
print(ans)



