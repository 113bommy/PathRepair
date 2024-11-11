n = int(input())
res = 0
i = 1
now = 1

while n >= now:
	n -= now
	res += 1
	i += 1
	now += i

print(res)