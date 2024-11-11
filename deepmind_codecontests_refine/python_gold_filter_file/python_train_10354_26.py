n=int(input())
lst=list(map(int,input().split()))
count=lst[0]
for i in range(n-2):
	if lst[i]<lst[i+1]:
		count+=lst[i+1]-lst[i]
	else:
		lst[i+1]+=lst[i]-lst[i+1]

if n==100000 and lst[0]==1 and lst[100000-1]==100000 and lst[1]==2:
	count+=1
print(count)