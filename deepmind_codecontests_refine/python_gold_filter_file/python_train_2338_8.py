n=int(input())
a=list(map(int,input().split()))
for i in range(n):
	if i>0:
		a[i]+=a[i-1]
x=0
ans=0
for i in range(n-1):
	if a[i]*3==a[n-1]*2:
		ans+=x
	if a[i]*3==a[n-1]:
		x+=1
print(ans)