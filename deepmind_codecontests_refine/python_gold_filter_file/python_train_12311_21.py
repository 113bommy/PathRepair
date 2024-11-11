import sys

def input():    return sys.stdin.readline().strip()
def iinput():   return int(input())
def rinput():   return map(int, sys.stdin.readline().strip().split()) 
def get_list(): return list(map(int, sys.stdin.readline().strip().split())) 
mod = int(1e9)+7

for _ in range(iinput()):
	a, b, c = rinput()
	if a>=c:
		print(-1 , b)
	else:
		if (c == a*b):
			print(1, -1)
		elif (a*b<c):
			print(b, -1)
		else:
			print(1 , b)