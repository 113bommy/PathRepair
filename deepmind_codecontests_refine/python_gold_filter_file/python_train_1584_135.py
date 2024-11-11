import sys
from math import sqrt, floor, factorial
from collections import deque, Counter
inp = sys.stdin.readline
read = lambda: list(map(int, inp().strip().split()))

def c_p(n):
	for i in range(2,int(sqrt(n))+1):
		if n % i == 0:
			return(True)
	return(False)
def solve():
	n = int(inp()); s = 4
	while not (c_p(s) and c_p(s+n)):
		s += 1
	print(s+n, s)


if __name__ == "__main__":
	solve()