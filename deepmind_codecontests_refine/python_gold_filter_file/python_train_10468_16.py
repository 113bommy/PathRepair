val = list(input())
ch = str(val[0]);vl = int(val[1])
if ((ch=="a" or ch=="h")):
	if (vl == 8 or vl == 1):
		print(3)
	elif (vl>1 and vl<8):
		print(5)
elif (ch>"a" and ch<"h") and (vl==1 or vl==8):
	print(5)
else:
	print(8)