a = int(input())
b = int(input())
c = int(input())
t = 0

if b<2 or c<4 or a<1:
	print("0")
else:
	t = min(a,b//2,c//4)*(7)
	print(t)