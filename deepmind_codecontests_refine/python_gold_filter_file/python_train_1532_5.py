from sys import stdin
from functools import reduce
from operator import ior
def get_ints(): return list(map(int, stdin.readline().strip().split()))

nk ,m = get_ints()
a = [int(input(),2) for x in range(nk)]
if nk == 1:
	print("NO")
	exit()
num =  reduce(ior,a)
for i in range(nk):
	k = a.copy()
	k.pop(i)
	n = reduce(ior,k)
	if n == num:
		print("YES")
		exit()
print("NO")