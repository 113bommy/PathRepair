m = int(input())
b = list(map(int, input().split()))

d = dict()
for i in b:
	if i in d:
		d[i] += 1
	else:
		d[i] = 1

t = list(d.keys())
t.sort()

i = len(t) - 2
while i >= 0:
	if d[t[i]] > 1:
		t.append(t[i])
	i -= 1

print(len(t))
print(' '.join(map(str, t)))