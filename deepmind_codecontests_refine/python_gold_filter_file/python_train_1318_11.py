# ANSHUL GAUTAM
# IIIT-D

s = input()
if(s.count('-') == 0):
	print("YES")
else:
	o = 0
	dash = 0
	for i in s:
		if(i == 'o'):
			o += 1
		else:
			dash += 1
	if(o == 0):
		print("YES")
	else:
		if(dash%o == 0):
			print("YES")
		else:
			print("NO")