n=int(input())

if n % 3 == 2 and n >= 2:
	min = 1
elif n %3 == 1 and n >= 7: 
	min = 2
elif n%3 == 0 and n >= 15:
	min = 3
else:
	print("0")
	quit()  

zac,end = 0, n+47

while end - zac > 1:
	str = (end+zac)//2
	if n >= (3*str*str+str)//2:
		zac = str
	else:
		end = str

max = zac

print((max - min + 3)//3)