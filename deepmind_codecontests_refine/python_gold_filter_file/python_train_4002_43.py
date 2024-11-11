

s=input()
arr=list(s)
con1=list(filter(lambda x:x>="A" and x<="Z",arr))
if len(con1)>0 and len(arr)>=5:
	con2=list(filter(lambda x:x>="a" and x<="z",arr))
	if len(con2)>0:
		con3=list(filter(lambda x:x>="0" and x<="9",arr))
		if len(con3)>0:
			print("Correct")
		else:
			print("Too weak")
	else:
		print("Too weak")
else:
	print("Too weak")