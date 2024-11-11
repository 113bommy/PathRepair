n,x = map(int,input().split())
mn,mx = 1000,0
for i in range(n) : 
	a,b = map(int,input().split())
	mn = min(mn,max(a,b))
	mx = max(mx,min(a,b))
if mn < mx : 
	print("-1")
elif x >= mx and x <= mn :
	print("0")
elif x > mn :
	print(x-mn)
else :
	print(mx-x)