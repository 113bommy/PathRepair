import random, math
from copy import deepcopy as dc


# Function to call the actual solution
def solution(li, r):
	out = 0
	i = 0
	while r:
		out += ((r+1)//2) * li[i]
		r = r//2
		i += 1
	return out

# Function to take input
def input_test():
	n, l, r = map(int, input().strip().split(" "))
	n = list(map(int, bin(n)[2:]))
	out = solution(n, r)
	out1 = solution(n, l-1)
	print(out - out1)


input_test()
# test()