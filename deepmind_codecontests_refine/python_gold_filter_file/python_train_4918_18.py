from math import *
t = int(input())
output = []
for _ in range(t):
	n,a,b = list(map(int,input().split()))
	al = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
	s = ""
	prevs = ""
	for i in range(b):
		prevs += al[i]
	for i in range(a-b):
		prevs += prevs[b-1]
		print()
	s = prevs
	for i in range(n-a):
		s += s[len(s)-a]
	output.append(s)
for i in output:
	print(i)