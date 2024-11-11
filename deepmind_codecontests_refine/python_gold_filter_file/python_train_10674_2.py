n=input("")
n=int(n)
min=0
j=n%7
max=n//7*2
min=n//7*2

if j is 1:
	max+=1
if j >=2:
	max+=2
if j is 6:
	min+=1
print(min,max)



