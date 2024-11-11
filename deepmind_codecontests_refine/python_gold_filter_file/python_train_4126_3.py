num = int(input())
total = []

if(num<=81):
	i = 0
else:
	i = num-90
	
while(i<=num):
	aux = list(str(i))	
	soma = 0
	for j in aux:
		soma = soma + int(j)
	if(soma+i == num):
		total.append(i)		
	i = i+1
if(len(total)>0):
	print(len(total))
	[print(j) for j in total]
	print('')
else:
	print(0)

	



	
