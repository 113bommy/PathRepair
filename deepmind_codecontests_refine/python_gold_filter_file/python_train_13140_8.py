import sys
sys.setrecursionlimit(10**6)


def main(t):
	n = int(input())
	print(*sorted(map(int,input().split()),reverse=True))
	if t>1:
		main(t-1)
main(int(input()))