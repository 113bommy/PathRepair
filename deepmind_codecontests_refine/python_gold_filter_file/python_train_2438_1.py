from sys import stdin , stdout
from os import path
if path.exists("input.txt"):
	stdin = open("input.txt",'r')
wr = stdout.write
rd = lambda:stdin.readline().strip()
#---------------------------------------------
all = []
n = int(rd())
for _ in range(n):
	all.append(set(map(int,rd().split()[1:])))
out = [True]*n
for i in range(n):
	for j in range(n):
		if i != j and all[i] <= all[j]:
			out[j] = False
for i in range(n):
	print("YES" if out[i] == True else "NO")
