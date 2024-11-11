number = int(input())
numerator = 0
denominator = 0
lst = list(map(int,input().split()))
lst2 = list(map(int,input().split()))
if len(lst) == 2 and len(lst2) == 2:
	num = 0
	den = 0
	for item in lst:
		num = num + item
	for item in lst2:
		den = den + item
	if den == 0:
		print("YES")
	elif num/den<=1:
		print("YES")
	else:
		print("NO")
else:
	numerator = 0
	for item in lst:
		numerator = numerator + item	
	second = lst2[0]
	for i in range(2):
		for item in lst2:
			if item > second:
				second = item
		denominator = denominator + second
		lst2.remove(second)
		second = lst2[0]
	if denominator == 0:
		print("YES")
	elif numerator/denominator<=1:
		print("YES")
	else:
		print("NO")
