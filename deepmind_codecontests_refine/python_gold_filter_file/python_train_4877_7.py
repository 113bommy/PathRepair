import sys
N = int(sys.stdin.readline())
data = [0] * 100000
for i in map(int,sys.stdin.readline().split()):
	data[i] += 1
print(max(map(sum,zip(data,data[1:],data[2:]))))
