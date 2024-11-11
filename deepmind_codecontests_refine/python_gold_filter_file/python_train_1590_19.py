n = int(input())
a = list(map(int,input().split()))
a.sort()
ans=10**18
i = 1
while i**(n-1)<10**12:
	count = 0
	for j in range(n):
		count += abs(a[j]-i**j)
	i+=1
	ans=min(ans,count)
print(ans)

