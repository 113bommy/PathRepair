# from debug import debug
import sys;input = sys.stdin.readline

t = int(input())
while t:
	t-=1
	n = int(input())
	lis = list(map(int, input().split()))
	S = sum(lis)
	X = 0
	for i in lis: X = X^i
	if S == 2*X:
		print(0)
		print("")
	else:
		print(2)
		print(S+X, X)