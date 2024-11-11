n=int(input())
m=2*n
for i in range (2*n):
	if i*(i+1)==m:
		print("YES")
		break
else :
	print("NO")