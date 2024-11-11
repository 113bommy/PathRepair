#brrute hai
def f(a,k):
	tc=0
	ans=[0]*(len(a))
	st=[]
	a=sorted(a)
	# print(a)
	# cans=0
	tl=0
	pref=0
	pref=[0]*(len(a)+1)
	for i in range(0,len(a)):
		# print(pref)
		if i>0:
			pref[i]=pref[i-1]+a[i]
		else:
			pref[i]=a[i]
		tl+=1
		if tl>k:
			ans[i]=pref[i]+ans[i-k]
		else:
			ans[i]=pref[i]
	return ans
n,m=map(int,input().strip().split())
l=list(map(int,input().strip().split()))
print(*f(l,m))