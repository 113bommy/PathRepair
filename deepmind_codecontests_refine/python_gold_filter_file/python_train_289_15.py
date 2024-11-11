s=input()
for i in range(len(s)):
	for j in range(i+1):
		if s[:j]+s[i:]=="keyence":
			print("YES")
			exit()
print("NO")