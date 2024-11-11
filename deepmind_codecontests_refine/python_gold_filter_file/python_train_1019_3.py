n = int(input())
S = input()
b = 0
w = S.count('.')
res = w
for s in S:
	if s == '.':
		w -= 1
	else:
		b += 1
	res = min(res,b+w)
print(res)
	