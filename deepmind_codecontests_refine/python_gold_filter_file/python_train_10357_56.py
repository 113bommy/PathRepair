n = int(input())
d = {0:"zero",1:"one",2:"two",3:"three",4:"four",5:"five",6:"six"\
	,7:"seven",8:"eight",9:"nine",10:"ten",11:"eleven",12:"twelve"\
	,13:"thirteen",14:"fourteen",15:"fifteen",16:"sixteen",17:"seventeen",\
	18:"eighteen",19:"nineteen"}


if n in d:
	print(d[n])
elif n//10 == 4:
	if n%10:
		print("forty"+"-"+d[n%10])
	else:
		print("forty")
elif n//10 == 5:
	if n%10:
		print("fifty"+"-"+d[n%10])
	else:
		print("fifty")
elif n//10 == 3:
	if n%10:
		print("thirty"+"-"+d[n%10])
	else:
		print("thirty")
if n//10 == 2:
	if n%10:
		print("twenty"+"-"+d[n%10])
	else:
		print("twenty")
elif n//10 == 8:
	if n%10:
		print(d[n//10]+"y-"+d[n%10])
	else:
		print(d[n//10]+"y")
elif n//10 > 5:
	if n%10:
		print(d[n//10]+"ty-"+d[n%10])
	else:
		print(d[n//10]+"ty")
