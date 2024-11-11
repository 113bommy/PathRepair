n, y1 = map(int, input().split())
a = list(map(int, input().split()))
m, y2 = map(int, input().split())
b = list(map(int, input().split()))

ans = 2

for i in range(31):
	step = (2 << i)
	half = (step >> 1)

	counts = dict()

	for x in a:
		rem = x % step
		count = counts.get(rem, 0)
		counts[rem] = count + 1
	
	for x in b:
		rem = (x + half) % step
		count = counts.get(rem, 0)
		counts[rem] = count + 1
	
	res = max(counts.values())
	ans = max(ans, res)

print(ans)