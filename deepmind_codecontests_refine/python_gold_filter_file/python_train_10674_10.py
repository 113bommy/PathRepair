n = int(input())

if n%7 == 0:
	out1 = 2*(n//7)
	out2 = 2*(n//7)

elif n%7 ==6:
	out1 = 2*(n//7)+1
	out2 = 2*(n//7)+2
else:
	out1 = 2*(n//7) 
	out2 = 2*(n//7) + min(n%7,2)

print(out1,out2,sep=" ")