x=input()
c = x[0]
d=int(x[1])


if d<8 and d>1 and c<"h" and c>"a":
	print(8)
elif (d<8 and d>1) or (c<"h" and c>"a"):
	print(5)
elif (c=="a" or c == "h") and (d == 1 or d == 8):
	print(3)
		
 