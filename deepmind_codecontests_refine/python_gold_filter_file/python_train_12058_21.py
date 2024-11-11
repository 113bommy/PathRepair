n = int(input())
w = []
w.append(input())
for i in range(1, n):
	W = input()
	if W in w or W[0] != w[i-1][len(w[i-1])-1]:
		print("No")
		exit(0)
	w.append(W)
print("Yes")