def function(n):
	n = n+1
	while(n%10==0):
		n=n/10
	return n 
n = int(input())
reached = [n]
number = function(n)
while(number not in reached):
	reached.append(number)
	number = function(number)
print(len(reached))

