n = int(input())

dir = input()
seq = list(map(int, input().split()))

min = 1000000000
for i in range(1, n):
	if dir[i-1] == "R" and dir[i] == "L":
		if (seq[i] - seq[i-1])/2 < min:
			min = (seq[i] - seq[i-1])/2

if min == 1000000000:
	print("-1")
else:
	print(int(min))