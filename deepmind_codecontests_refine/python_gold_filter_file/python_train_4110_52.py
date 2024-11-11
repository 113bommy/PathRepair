a,b,c,d = map(int, input().split())
if (max(3*a/10, a - c*a/250)==max(3*b/10, b - d*b/250)):
	print("Tie")
elif(max(3*a/10, a - c*a/250)>max(3*b/10, b - d*b/250)):
	print("Misha")
else:
	print("Vasya")	
