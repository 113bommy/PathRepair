x,y = map(int,input().split())
if (x+y)%3==0 or x%3==0 or y%3==0:
	print("Possible")
else:
	print("Impossible")
