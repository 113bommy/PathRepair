n = int(input())
a = list(map(int, input().split()))
v = [0,0,0]

for i in a:
	if i == 1:
		v[0] += 1
	elif i == 2:
		v[1] += 1
	else:
		v[2] += 1

print(len(a) - max(v))