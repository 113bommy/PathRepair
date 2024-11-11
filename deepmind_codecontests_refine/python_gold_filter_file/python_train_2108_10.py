for t in range(int(input())):
	n = int(input())
	day = len(bin(n)[2:])-1
	ans = []
	k = 1	
	count = day
	while k<=n:
		ans.append(k)
		n-=k
		k*=2
	
	if n>0:
		ans.append(n)
		ans.sort()
	ans1 = []
	for i in range(1,len(ans)):
		ans1.append(ans[i]-ans[i-1])
	print(len(ans)-1)
	print(*ans1)
		
