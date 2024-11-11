s = input()
t = s.replace('x','')
if t != t[::-1]:
	print(-1)
	exit()
x = []
cnt = 0
for i in s:
	if i == 'x':
		cnt += 1
	else:
		x.append(cnt)
		cnt = 0
else:
	x.append(cnt)
res = 0
for i in range(len(x)//2):
	res += abs(x[i]-x[-i-1])
print(res)
