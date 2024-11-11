import sys
input = sys.stdin.readline

n, x, y = map(int, input().split())
l = list(map(int, input().split()))
if n == 1:
	print(1)
	exit(0)
for i in range(x):
	q = min(n, i+1+y)
	s = l[:i] + l[i+1:i+1+y]
	if s == []:
		print(i + 1)
		exit(0)
	if l[i] < min(s):
		print(i + 1)
		exit(0)
for i in range(x, n):
	q = min(n, i+1+y)
	s = l[i-x:i] + l[i+1:q]
	#print(l[i], s)
	if s == []:
		print(i + 1)
		exit(0)
	if l[i] < min(s):
		print(i + 1)
		exit(0)