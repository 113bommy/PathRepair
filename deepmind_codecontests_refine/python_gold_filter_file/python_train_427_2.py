import sys
n = int(input())
c = list(map(int, input().split()))
t = list(map(int, input().split()))

if c[0] != t[0] or c[n-1] != t[n-1]:
	print("No")
	sys.exit()
if n == 2:
	print("Yes")
	sys.exit()
g1 = [c[i+1] - c[i] for i in range(n-1)]
g2 = [t[i+1] - t[i] for i in range(n-1)]
if sorted(g1) == sorted(g2):
	print("Yes")
else:
	print("No")