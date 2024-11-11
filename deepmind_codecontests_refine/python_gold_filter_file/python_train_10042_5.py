n=int(input())
l=[(i*(i+1))//2 for i in range(1,33)]
if n in l:
	print("YES")
else:
	print("NO")	