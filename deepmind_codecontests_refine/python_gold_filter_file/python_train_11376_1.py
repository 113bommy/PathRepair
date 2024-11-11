from os import path;import sys,time
# mod = int(1e9 + 7)
from math import ceil, floor,gcd,log,log2 ,factorial,sqrt
from collections import defaultdict ,Counter , OrderedDict , deque;from itertools import combinations,permutations
# from string import ascii_lowercase ,ascii_uppercase
from bisect import *;from functools import reduce;from operator import mul;maxx = float('inf')
I = lambda :int(sys.stdin.buffer.readline())
lint = lambda :[int(x) for x in sys.stdin.buffer.readline().split()]
S = lambda: sys.stdin.readline().strip('\n')
grid = lambda  r :[lint() for i in range(r)]
localsys = 0
start_time = time.time()
#left shift --- num*(2**k) --(k - shift)
nCr = lambda n, r: reduce(mul, range(n - r + 1, n + 1), 1) // factorial(r)
def ceill(n,x):
    return (n+x -1 )//x
T =1
def solve():
	n , l = lint()
	i , j, cura , curb,ans ,ja , jb, a    = 0 , n-1 , 0 , l , 0 , 1 , 1, lint()
	while True:
		if i > j :
			ans+=(curb - cura) /(ja+jb)
			break
		t1, t2  = (a[i] - cura)/ja , (curb- a[j])/jb
		if t1 < t2 :
			cura ,ja , i , ans , curb= a[i] , ja +1 , i +1 , ans + t1 , curb - t1*jb
		elif t1 > t2 :
			curb , j , jb , cura , ans  = a[j] , j-1 , jb +1 , cura + t2*ja , ans + t2
		else:
			cura , curb , i , j, ja , jb , ans = a[i] , a[j] , i +1 , j - 1 , ja + 1 , jb + 1 , ans + t1
	print(ans)




		







def run():
    if (path.exists('input.txt')):
        sys.stdin=open('input.txt','r')
        sys.stdout=open('output.txt','w')


run()
T = I() if T else 1
for _ in range(T):
    solve()


if localsys:
    print("\n\nTime Elased :",time.time() - start_time,"seconds")


