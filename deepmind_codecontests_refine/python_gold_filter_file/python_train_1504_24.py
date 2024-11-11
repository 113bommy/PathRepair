#import sys
#sys.stdin = open("123.data")
t = int(input())
l = -2000000000
r =  2000000000
while t > 0:
	zn, n, fl = map(str, input().split())
	n = int(n)
	if fl == 'Y':
		if zn == '>':
			l = max(l, n + 1)
		elif zn == '<':
			r = min(r, n - 1)
		elif zn == '>=':
			l = max(l, n)
		elif zn == '<=':
			r = min(r, n)
	else:
		if zn == '>':    #<=
			r = min(r, n)
		elif zn == '<':  #>=
			l = max(l, n)
		elif zn == '>=': # <
			r = min(r, n - 1)
		elif zn == '<=': # >
			l = max(l, n + 1)
	if r < l:
		print('Impossible')
		exit()
	t -= 1
print((l + r) // 2)




