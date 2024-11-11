n, x = map(int,input().split())
count = 0
for _ in range(n):
	s = input()
	s = int(s.replace(' ',''))
	a = x+s
	if a>=0:
		x += s
	else:
		count+=1
print(x, count)