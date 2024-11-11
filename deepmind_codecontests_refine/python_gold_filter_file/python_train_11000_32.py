n = int(input())
count = 0
arr = [100,20,10,5,1]
for i in arr:
	count+=(n//i)
	n-=(n//i)*i
print(count)	