X,A,B=map(int,input().split())
if A>=B:
	print("delicious")
elif B>A and X+A>=B :
	print("safe")
else:
	print("dangerous")