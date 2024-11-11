val=int('1'+'0'*5)
freequency=[0]*(val+1)
n=int(input())
l=list(map(int,input().split()))
for x in range(n):
	freequency[l[x]]+=1
ans=1
for x in range(2,val+1):
	count=0
	for y in range(x,val+1,x):
		count+=freequency[y]
	ans=max(ans,count)
print(ans)