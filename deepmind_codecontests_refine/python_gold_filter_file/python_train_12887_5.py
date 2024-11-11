import bisect

n = int(input())
d = list(map(int, input().split()))
d.sort()

m = 0

for a in range(n-2):
	for b in range(a+1,n-1):
		m+=bisect.bisect_left(d,d[a]+d[b])-1-b

print(m)