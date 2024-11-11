n,d = map(int,input().split())
t = input()
k = 0
i = 0
while i < n:
	flag = 0
	if i+d >= n-1:
		k = k + 1
		break
	for j in range(d,0,-1):
		if t[i+j] == "1":
			k = k + 1
			flag = 1
			break
	if flag == 0:
		print(-1)
		exit()
	i = i + j
print(k)