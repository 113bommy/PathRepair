n = int(input())
p = list(map(int, input().split()))
p.sort()
ao = list(range(1, n, 2))
ae = list(range(2, n+1, 2))
do = [abs(p[i] - ao[i]) for i in range(len(p))]
de = [abs(p[i] - ae[i]) for i in range(len(p))]
print(min(sum(do), sum(de)))
	
