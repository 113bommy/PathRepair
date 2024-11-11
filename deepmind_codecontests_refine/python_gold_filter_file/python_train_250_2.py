n, k = map(int, input().split())
a = list(map(int, input().split()))

res = a[0]
for l in range(n):
	for r in range(l, n):
		inside = sorted(a[l:r+1])
		outside = sorted(a[:l] + a[r+1:], reverse=True)
		
		new_res = sum(inside)
		for i in range(min(k, len(inside), len(outside))):
			if outside[i] > inside[i]:
				new_res += outside[i]-inside[i]
			else:
				break
		if new_res > res:
			res = new_res

print(res)
