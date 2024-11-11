n=int(input())
qa=[n+1]
for i in range(1,int(n**(1/2))+1):
	if n%i==0:
		qa.append(i-1+(n//i)-1)
print(min(qa))