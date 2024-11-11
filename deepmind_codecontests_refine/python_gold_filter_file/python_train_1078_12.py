'''input
3
'''
n = int(input())
if n < 3:
	print(-1)
else:
	print(((10**(n-1))//210+1)*210)