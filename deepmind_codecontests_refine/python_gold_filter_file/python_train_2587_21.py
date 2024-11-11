k,s=map(int,input().split())
count=0
for i in range(0,k+1):
	for g in range(0,k+1):
		if k>=s-i-g>=0:
			count+=1
print(count)