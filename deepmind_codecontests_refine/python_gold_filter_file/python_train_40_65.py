n,k=[int(x) for x in input().split()]
counter=n
while n>=k:
	counter+=n//k
	n=n//k + n%k
print(counter)