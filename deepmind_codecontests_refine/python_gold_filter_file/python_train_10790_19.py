l,r,a = map(int,input().split())
ans=0
if(a>=abs(l-r)):
	if(l>r):
		a=a-(l-r)
		ans=l*2+((a//2)*2)
	else:
		a=a-(r-l)
		ans=r*2+((a//2)*2)
else:
	ans=(min(l,r)+a)*2
print(ans)
