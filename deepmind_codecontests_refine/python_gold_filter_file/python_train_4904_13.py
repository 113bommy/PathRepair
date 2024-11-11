i = int(input())

if i <= 2:
	print("No")
else:
	total_sum = i * (i + 1) / 2
	alone = None
	if i % 2 == 0:
		alone = i // 2
	else:
		alone = (i + 1) // 2
	print("Yes")
	print("1", alone)
	rest = set(range(1, i + 1))
	rest.remove(alone)
	print("{} {}".format(i - 1, " ".join((str(x) for x in rest))))
