n=int(input())
a=list(map(int,input().split()))
if(0 in a and 1 in a):
	print("hard")
elif(1 in a):
	print("hard")
else:
	print("easy")
