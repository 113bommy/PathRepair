inp = input()
n,k = inp.split()
n,k = int(n),int(k)
a = input()
a = [int(i) for i in a.split()]
a.sort()
##print(a)
i,j,ans=n-1,n-2,0
while i>=0 and j>=0:
	if (a[i]<=a[j]+k) and (a[i]>a[j]):
		ans+=1
		j-=1
	elif i-1==j:
		i=i-1
		j=j-1
	else:
		i-=1
print(n-ans)