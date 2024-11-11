i = int(input())
ans = []
for _ in range(i):
	a = int(input())
	b = list(map(int,input().split()))
	b.sort()
	h =b[-2]
	p = max(0,min(a-2,h-1))
	ans.append(p)
for i in ans:
	print(i)

	