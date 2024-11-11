from sys import stdin

n = int(input(''))
operations=list()
for i in range(n):
	operations.append([str(i) for i in stdin.readline().split()]) 
x = 0

for operation in operations:
	if   str(operation[0]) == '++X' or str(operation[0]) == 'X++' :
		x+=1
	else:
		x-=1

print(x)
