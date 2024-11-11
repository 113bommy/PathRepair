from collections import  Counter
def f(a,n):
	cnt=[0]*(n+2)
	for i in a:
		cnt[i]+=1
	cnt2=cnt.copy()
	cnt3=cnt.copy()
	i=0
	d=2
	mx=0
	right=False
	while i<n+1:
		if cnt[i]==0:
			d+=1
		else:
			j=i-1
			s=0
			while j+1<n+1 and cnt[j+1]:
				j+=1
				s+=cnt[j]
			mx+=j-i+1
			if s>j-i+1 and (right==False or d>1):
				s-=1
				mx+=1
			right=False
			if s>j-i+1:
				right=True
				mx+=1
			i=j
			d=0
		i+=1
	cnt=cnt2
	for i in sorted(a):
		if cnt[i]>1:
			if cnt[i-1]==0 :
				cnt[i-1]+=1
				cnt[i]-=1
			if cnt[i+1]==0 and cnt[i]>1:
				cnt[i+1]+=1
				cnt[i]-=1
			if cnt[i]>1:
				cnt[i+1]+=cnt[i]-1
				cnt[i]=1
	# print(cnt)
	mx=max(mx,(n+2)-cnt.count(0))
	l=sorted(list(set(a)))
	if len(l)==1:
		return 1,mx
	i=0
	mn=0
	cnt=cnt3
	while i<n+1:
		if cnt[i]==0:
			i+=1
		else:
			mn+=1
			i+=3
	return (mn,mx)
n=int(input())
a=list(map(int,input().strip().split()))
print(*f(a,n))