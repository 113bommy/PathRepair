import sys
from math import sqrt, gcd, ceil, log
# from bisect import bisect, bisect_left
from collections import defaultdict, Counter, deque
# from heapq import heapify, heappush, heappop
input = sys.stdin.readline
read = lambda: list(map(int, input().strip().split()))

# sys.setrecursionlimit(10**9)

def main():
	n, m = read(); s = input().strip(); t = input().strip()
	ans = s[0] + s[-1] + t[0]+ t[-1]
	# print(ans)
	if ans in ("<>v^", "><^v"):print("YES")
	else:print("NO")






	


if __name__ == "__main__":
	main()