
import math
t = input()
rt = t.replace('a',"");
length = len(rt)//2;
if len(rt)%2 != 0 :
	print(":(")
else :

	res = (t[0:len(t)-length])
	var = (t[len(t)-length:len(t)])

	# print(var)
	sea = res.replace('a',"")
	# print(sea)
	if sea == var:
		print(res)
	else :
		print(":(")