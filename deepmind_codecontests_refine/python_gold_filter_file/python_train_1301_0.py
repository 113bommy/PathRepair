n,k=list(map(int,input().split()))
a=list(map(int,input().split()))
s=0
a.sort(key=lambda x: x%10)
#~ while k>0:
for i in range(n-1,-1,-1):
	if a[i]<100:
		t=10-a[i]%10
		k-=t
		if k>-1:
			a[i]+=t
		else:
			break
for i in a:
	s+=i//10
k//=10
if k!=-1:s=min(n*10,s+k)
print(s)
