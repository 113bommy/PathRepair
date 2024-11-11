q=int(input())
for _ in range(q):
	n=int(input())
	caros=list(map(int,input().split(" ")))

	if (caros.count(caros[0])==n):
		print(1)
		ans=[1]*n
		print(*ans,sep=' ')
		continue

	flag=0
	ind=0

	for i in range(n):
		if (caros[i]==caros[(i+1)%n]):
			ind=i
			flag=1
			break

	if (flag!=1 and n%2!=0):
		print(3)
		ans=[1,2]*(n//2)
		ans+=[3]
		print(*ans,sep=' ')
		continue

	if (n%2==0):
		print(2)
		ans=[1,2]*(n//2)
		print(*ans,sep=' ')
		continue

	ans=[0]*n
	ind=ind+1
	for i in range(ind,ind+n):
		index=(i)%n
		#print("index = ",index)
		if (ans[index-1]!=1):
			ans[index]=1
		else:
			ans[index]=2
		#print(ans)
	print(2)
	print(*ans,sep=' ')