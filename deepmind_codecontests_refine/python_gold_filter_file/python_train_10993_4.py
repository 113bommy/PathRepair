'''input
92
'''
n = int(input())
l = ['Sheldon', 'Leonard', 'Penny', 'Rajesh', 'Howard']
if n < 5:
	print(l[n-1])
else:	
	x = -1
	while 10*(2**x-1)+6 <= n:
		x += 1
	x-=1
	x1 = int(10*(2**x-1)+6)
	print(l[(n-x1)//(2**(x+1))])





