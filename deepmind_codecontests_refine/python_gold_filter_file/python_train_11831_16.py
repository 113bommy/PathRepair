s = input()
ans = 0;
chk = "13579aeiou"
for a in s:
	for b in chk:
		if b == a:
			ans += 1
print(ans)
