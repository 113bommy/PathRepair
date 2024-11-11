
def mi():
	return map(int, input().split())

n = int(input())
odd = []
even = []
if n%2:
	if n==1:
		print ('No')
	else:
		print ('Yes')
		for i in range(1,n+1):
			if i%2:
				odd.append(i)
		print (len(odd), *odd)
		for i in range(1,n+1):
			if i%2==0:
				even.append(i)
		print (len(even), *even)
else:
	if n==2:
		print ('No')
	else:
		print ('Yes')
		for i in range(1,n+1):
			if i%2:
				odd.append(i)
		print (len(odd), *odd)
		for i in range(1,n+1):
			if i%2==0:
				even.append(i)
		print (len(even), *even)