n = int(input())
s = [int(i) for i in input().split()]
x,y = set(),set()

for i in range(n):
	if s[i] not in x:
		x.add(s[i])
	else:
		y.add(s[i])
a = len(x)
b = len(y)
x = sorted(list(x))
y = list(y)
y.sort(reverse=True)

if a+b==n:
	print("YES")
	print(a)
	print(*x)
	print(b)
	print(*y)
	print
else:
	print("NO")