N = int(input())
a = list(map(int, input().split()))
b = []
for i in range(-100, 101):
	t = 0
	for j in a:
		t += (j - i) ** 2
	b.append(t)
print(min(b))