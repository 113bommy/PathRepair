n = int(input())
numbers = []
for i in range(n):
	number = (input())
	numbers.append(number)
a = numbers.count('--X')
b = numbers.count('X--')
c = numbers.count('X++')
d = numbers.count('++X')
finally_number = +c+d-a-b
print (finally_number) 
