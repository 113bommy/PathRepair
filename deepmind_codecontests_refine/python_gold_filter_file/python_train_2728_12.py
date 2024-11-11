# c a _ c

T = 1
T = int(input())
 
for t in range(1, T + 1):
	n = int(input())
	a = list(map(int, input().split()))
	flag = False
	for i in range(1, n):
		if(abs(a[i] - a[i - 1]) > 1):
			print("YES")
			print(i, i + 1)
			flag = True
			break
	if not flag:
		print("NO")