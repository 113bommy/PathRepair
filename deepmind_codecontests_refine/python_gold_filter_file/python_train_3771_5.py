n = int(input())
s = input()
l = [[0, -1] for i in range(26)]
for i in range(n):
	l[ord(s[i]) - 97][0] += 1
j = -1
color = [-1 for i in range(n)]
for c in range(26):
	#print(c, end = "")
	#for r in color:
	#	print(r, end = "")
	#print()
	i = j + 1
	while l[c][0] > 0 and i < n:
		if ord(s[i]) - 97 == c:
			if l[c][1] == -1:
				was0 = False
				was1 = False
				for k in range(i):
					if ord(s[k]) - 97 > ord(s[i]) - 97:
						if color[k] == 0:
							was0 = True
						if color[k] == 1:
							was1 = True
				if was0 and was1:
					print("NO")
					exit(0)
				if was0:
					color[i] = 1
					l[c][1] = 1
				else:
					color[i] = 0
					l[c][1] = 0
			else:
				color[i] = l[c][1]
			l[c][0] -= 1
			j = i
		i += 1
	mx = ord(s[j]) - 97
	#print(color)
	for i in range(j):
		#print(str(j) + " " + str(color))
		if color[i] != -1:
			continue
		if ord(s[i]) - 97 > ord(s[j]) - 97:
			#print(" " + str(color[i]) + " " + str(color[j]))
			color[i] = 1 - color[j]
			if mx > ord(s[i]) - 97:
				print("NO")
				exit(0)
			mx = ord(s[i]) - 97
for j in range(n):
	for i in range(j):
		if ord(s[i]) - 97 > ord(s[j]) - 97 and color[i] == color[j]:
			print("NO")
			exit(0)
print("YES")
for c in color:
	print(c, end = "")