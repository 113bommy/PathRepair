import sys
import os
if sys.platform=="darwin":
	base = os.path.dirname(os.path.abspath(__file__))
	name = os.path.normpath(os.path.join(base, '../Documents/input.txt'))
	#print(name)
	sys.stdin = open(name)

x = int(input())
chk = 0
i = 1

while chk < x:
	chk = chk + i
	i = i + 1
	#print(chk,i)

print(i-1)
