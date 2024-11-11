N =int(input())
i =1
a =0
while i <= N:
	if i%3 != 0 and i%5 != 0:
		a +=i
	i +=1
print(a)
