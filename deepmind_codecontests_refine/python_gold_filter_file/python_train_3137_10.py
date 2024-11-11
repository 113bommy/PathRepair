t=int(input())
for j in range(t):
	a=list(input())
	n=len(a)
	alpha=0
	#print(n,n//2)
	for i in range(n//2):
		#print("hello")
		if(a[i]==a[n-1-i]):
			alpha=1

		else:
			#print(a[i],a[n-i-1])
			alpha=0
			break
	if(alpha==0 and n!=1):
		#print("why")
		print(''.join(a))
	else:
		b=list(set(a))
		if(len(b)==1):
			print("-1")
		else:
			a.sort()
			print(''.join(a))