import sys

n = int(sys.stdin.readline())

if(n <= 2):
	print(-1)
	exit()
	
res = []
for i in range(2, n + 1):
	res.append(str(i))
	
res.append(str(1))
print(" ".join(res))
