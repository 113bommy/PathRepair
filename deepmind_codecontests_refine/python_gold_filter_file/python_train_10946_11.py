[a,b,c] = [int(x) for x in input().split()]
def test(a,b,c) :
	k = 0
	if min(a,b,c) == c:
		if a ==  1 and b == 1 :
			k = 3
		elif  a == 1 and b == 2 :
			k = 3
		elif  a == 1 and b > 2 :
			k = 3
		elif a == 2 and b == 1  :
			k = 4
		elif a == 2 and b > 1   :
			k = 5
		elif a > 2 and  b == 1  :
			k = 5
		else :
			k = 6


	elif  min(a,b,c) == b :
			
		if a == 1 and c == 1 :
			k = 3
		elif a == 1 and c ==2 :
			k = 4
		elif a == 1 and c >=2 :
			k = 4
		elif a == 2 and c == 1:
			k = 4
		elif a == 2 and c > 1 :
			k = 4 
		elif a > 2 and c == 1  :
			k = 5
		else  :
			k = 6


	elif min(a,b,c) == a :
		if a == 1:
			if b == 1 and c == 1 :
				k = 3
			elif b == 1 and c ==2 :
				k = 4
			elif b == 1 and c >=2 :
				k = 4
			elif b == 2 and c == 1:
				k = 3
			elif b == 2 and c > 1 :
				k = 5 
			elif b > 2 and c == 1  :
				k = 3
			else  :
				k = 5

		elif a == 2 :

			if b == 1 and c == 1 :
				k = 4
			elif b == 1 and c ==2 :
				k = 5
			elif b == 1 and c >=2 :
				k = 5
			elif b == 2 and c == 1:
				k = 5
			elif b == 2 and c > 1 :
				k = 6 
			elif b > 2 and c == 1  :
				k = 5
			else  :
				k = 6
	return k


if a < 3 or b < 2 or c < 2 :
	print(test(a,b,c))
else :

	m = (min((a//3) ,(b//2), (c//2)) )
	a = a - (m*3)
	b = b - (m*2)
	c = c - (m*2)
	m = m*7

	if a == 0  :
		if min(b,c) >= 1:
			print(m+2)
		elif min(b,c) == 0 and max(b,c)== 1 :
			print(m+1)
		else :
			print(m)
	elif b == 0:
		if min(a,c) >= 2 :
			print(m+3)
		elif c == 2 and a == 1:
			print(m+3)
		elif c== 1 and a >= 1 :
			print(m+2)
		elif c== 1 and a == 0:
			print(m+1)
		elif c== 0 and a >= 2:
			print(m+2)
		elif c==0 and a == 1:
			print(m+1)
		elif c==0 and a == 0:
			print(m)
	elif c == 0 :
		if min(a,b) >= 2 :
			print(m+4)
		elif b == 2 and a == 1:
			print(m+2)
		elif b== 1 and a >= 1 :
			print(m+3)
		elif b== 1 and a == 0:
			print(m+1)
		elif b== 0 and a >= 2:
			print(m+1)
		elif b==0 and a == 1:
			print(m+1)
		elif b==0 and a == 0:
			print(m)
	else :
		print(test(a,b,c) + m)












		









