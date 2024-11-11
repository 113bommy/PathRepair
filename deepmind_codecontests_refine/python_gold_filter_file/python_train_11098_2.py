A,B = input().split()
C = int(input())
if A == "^":
	a = 0
elif A == ">":
	a = 1
elif A == "v":
	a = 2
else:
	a = 3
if B == "^":
	b = 0
elif B == ">":
	b = 1
elif B == "v":
	b = 2
else:
	b = 3

c = C % 4
if (a + c) % 4 == b and (a - c) % 4 == b:
	print("undefined")
elif (a + c) % 4 == b:
	print("cw")
elif (a - c) % 4 == b:
	print("ccw")
else:
	print("undefined")