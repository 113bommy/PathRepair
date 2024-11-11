n,k=map(int,input().split())
a=list(map(int,input().split()))
ans=0
b=[0,0]
t=0;tt=n;
o=[]
temp=0
s=[]
for i in range(n):
	temp+=a[i]
	s.append(temp)
	o.append(tt)
	if(a[n-i-1]==0):
		tt=n-i-1
o.reverse()
#print(*o)
l=0;r=-1;
for i in range(n):
	if(a[i]==1):
		b[a[i]]+=1
	else:
		if(b[0]<k):
			b[0]+=1
		else:
			if(a[t]==0):
				t+=1
			else:
				temp=1+s[o[t]]-s[t]
				b[1]-=temp
				t=o[t]+1
	if(ans<b[0]+b[1]):
		l=t
		r=i
		ans=b[0]+b[1]
for i in range(l,r+1):
	a[i]=1
print(ans)
print(*a)