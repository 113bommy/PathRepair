'''input
4
2 2 2 2
2 0 2 2
3 2 2 1
2 2 2 2
'''
n = int(input())
s, t, y = [], 0, []
for _ in range(n):
	i = list(map(int, input().split()))
	if 0 not in i:
		s.append(sum(i))
	else:
		t = i
	y.append(i)
if len(set(s)) == 1:
	x = s[0] - sum(t)
	z = t.index(0)
	for a in range(n):
		if 0 in y[a]:
			y[a] = t[:z] + [x] + t[z+1:]
	if all(sum([y[j][k] for j in range(n)]) == s[0] for k in range(n)) and x > 0:
		if sum([y[k][k] for k in range(n)]) == s[0]:
			if sum([y[l][n-l-1] for l in range(n)]) == s[0]:
				print(x)
				quit()
	print(-1)
elif len(set(s)) == 0:
	print(100)
else:
	print(-1)







