from math import ceil
n, t = map(int, input().split())
mi = 10**10
for i in range(n):
	s, d = map(int, input().split())
	if t < s:
		ans = s
	else:
		ans = s + ceil((t-s)/d)*d
	# print(ans)
	if ans < mi:
		# print('t')
		mi = ans
		ind = i+1
print(ind)
