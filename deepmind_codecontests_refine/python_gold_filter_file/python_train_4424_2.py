a = input()
b = "CODEFORCES"
if a[:len(b)] == b or a[-len(b):] == b:
	print("YES")
else:
	for x in range(len(b)):
		if a[x-len(b):] == b[x:] and a[:x] == b[:x]:
			print("YES")
			break
	else:
		print("NO")

