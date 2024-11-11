n,m=map(int,input().split())
a=list(map(int,input().split()))
k=a.count(1)
l=a.count(-1)
ans=''
for i in range(m):
	x,y=map(int,input().split())
	if ((y-x)+1)//2<=k and ((y-x)+1)//2<=l and ((y-x)+1)%2==0:
			ans+='1\n'
	else:
		ans+='0\n'
print(ans)