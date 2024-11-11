n = int(input())

a = "I hate that "
b = "I love that "

if n%2 == 0:
	print(int((n/2)-1)*(a+b) + "I hate that I love it")
if n%2 != 0:
	print(int(n/2)*(a+b) + "I hate it")