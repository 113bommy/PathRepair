q = int(input())

for i in range(q):
	n = int(input())
	print((sum(map(int,input().split()))+ n - 1)//n)