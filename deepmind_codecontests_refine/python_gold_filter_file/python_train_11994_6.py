n = int(input())
for i in range(n):
	t = list(input())
	flag = 0
	if len(t) == 1:
		if t[0] == "?":
			print("a")
			continue
	for j in range(1,len(t)):
		if t[j] == t[j-1] and t[j] != "?":
			print(-1)
			flag = 1
			break
	if flag == 1:
		continue
	if t[0] == "?":
		if t[1] == "a":
			t[0] = "b"
		elif t[1] == "c":
			t[0] = "a"
		elif t[1] == "b":
			t[0] = "c"
		elif t[1] == "?":
			t[0] = "a"
	for j in range(1,len(t)-1):
		if t[j] == "?":
			if t[j-1] == "a" and t[j+1] == "c" or\
			t[j-1] == "c" and t[j+1] == "a":
				t[j] = "b"
			elif t[j-1] == "a" and t[j+1] == "b" or\
			t[j-1] == "b" and t[j+1] == "a":
				t[j] = "c"
			elif t[j-1] == "b" and t[j+1] == "c" or\
			t[j-1] == "c" and t[j+1] == "b":
				t[j] = "a"
			elif t[j-1] in ["a","b","c"]:
				if t[j-1] == "a":
					t[j] = "b"
				elif t[j-1] == "c":
					t[j] = "a"
				elif t[j-1] == "b":
					t[j] = "c"
	if t[-1] == "?":
		if t[-2] == "a":
			t[-1] = "b"
		elif t[-2] == "c":
			t[-1] = "a"
		elif t[-2] == "b":
			t[-1] = "c"
	for j in t:
		print(j,end="")
	print()
