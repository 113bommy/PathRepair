l = list(map(int,input().split()))
l.sort()
l.reverse()
k = len(l) - 1
for i in range(len(l) - 2):
	if l[i] < l[i + 1] + l[i + 2]:
		print("TRIANGLE")
		exit()
for i in range(len(l) - 2):
	if l[i] == l[i + 1] + l[i + 2]:
		print("SEGMENT")
		exit()
print("IMPOSSIBLE")
