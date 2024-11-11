n=int(input())
i=0
j=0
while n>j:
	j=(i*(i+1))/2
	i+=1
print('YES' if j==n else 'NO')