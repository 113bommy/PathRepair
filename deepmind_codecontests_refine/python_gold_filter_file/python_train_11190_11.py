# problem statement: https://codeforces.com/problemset/problem/552/C

line = input()
w, m = map(int, line.split(" "))

while m > 0:
	if (m - 1) % w == 0:
		m -= 1
	elif (m + 1) % w == 0:
		m += 1
	elif m % w != 0:
		print("NO")
		exit(0)
	m //= w

print("YES")