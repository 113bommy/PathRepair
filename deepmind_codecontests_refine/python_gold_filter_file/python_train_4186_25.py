from sys import stdin,stdout
from collections import Counter
def ai(): return list(map(int, stdin.readline().split()))
def ei(): return map(int, stdin.readline().split())
def ip(): return  int(stdin.readline().strip())
def op(ans): return stdout.write(str(ans) + '\n')

t = ip()
for i in range(t):
	n = ip()
	s = input()
	if s.count('1') == 0:
		print(n)
	else:
		a,b= s.index('1'),s[::-1].index('1')
		print(2*(n-min(a,b)))