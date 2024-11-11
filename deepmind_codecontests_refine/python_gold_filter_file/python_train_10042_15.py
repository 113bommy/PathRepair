n=int(input())
a=[i*(i+1)//2 for i in range(1,n+1)]
if n in a:
	print("YES")
else:
	print("NO")