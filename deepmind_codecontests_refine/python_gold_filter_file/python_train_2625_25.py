'''input
6
5 6 2
2 4 3 5 7
5 11 2
2 4 3 5 7
2 10000 2
10000 10000
2 9999 2
10000 10000
5 13 2
8 2 8 2 5
3 18 2
1 2 3
'''
# A coding delight
from sys import stdin
import sys 

sys.setrecursionlimit(10 ** 5)


def check(index):
	aux = p
	for i in range(index, -1, -2):
		aux -= arr[i]
	return aux >= 0



def binary_search(start, end):
	while start < end:
		# print(start,  end)
		mid = (start + end + 1) // 2
		if check(mid):
			start = mid
		else:
			end = mid - 1
	if check(start):
		return start + 1
	else:
		return start 


# main starts
t = int(stdin.readline().strip())
for _ in range(t):
	n, p, k = list(map(int, stdin.readline().split()))
	arr = list(map(int, stdin.readline().split()))
	arr.sort()
	ans = 0
	ans = binary_search(0, n - 1)

	print(ans)
