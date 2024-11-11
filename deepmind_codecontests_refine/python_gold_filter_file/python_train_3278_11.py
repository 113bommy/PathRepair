s = input()
s = "00" + s
l = len(s)
for i in range(l):
	for j in range(i + 1, l):
		for k in range(j + 1, l):
			ts = s[i] + s[j] + s[k]
			if (int(ts) % 8 == 0):
				print("YES")
				print(int(ts))
				exit()
print("NO")