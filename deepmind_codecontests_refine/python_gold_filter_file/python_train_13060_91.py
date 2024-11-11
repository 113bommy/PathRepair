x = int(input())
if x%10  == 0 and x>10:
	print(x//2,x//2)
elif x%2 == 0:
	print(4,x-4)
else:
	print(9,x-9)
