from sys import stdin, stdout

n = int(stdin.readline())

units = ['8\n', '4\n', '2\n', '6\n']

if n == 0:
	stdout.write('1\n')
	exit()

stdout.write(units[(n - 1) % 4])