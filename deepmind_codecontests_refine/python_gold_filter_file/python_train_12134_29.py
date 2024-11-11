n = int(input())
x = list(map(int,input().split()))
result =1
l=1
for i in range(1,n):
	if x[i-1]<x[i]:
		l+=1
	else:
		if result<l:
			result=l
		l=1
if result<l:
	result=l
print(result)

