from math import ceil
a,b,c = map(int,input().split())
x,y,z = ceil(a/2),ceil(b/2),ceil(c/2)
maxi = max(x,y,z)
if maxi == z:
	print(32+3*ceil((c-2)/2))
elif maxi == y:
	print(31+3*ceil((b-2)/2))
elif maxi == x:
	print(30+3*ceil((a-2)/2))
