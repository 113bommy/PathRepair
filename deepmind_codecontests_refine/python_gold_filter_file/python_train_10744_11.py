for i in range(int(input())):
	a,b,c= sorted(map(int,input().split()))	
	if a+b >= (c-1):
		print("Yes")
	else:
		print("No")
