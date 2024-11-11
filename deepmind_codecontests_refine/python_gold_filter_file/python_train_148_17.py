l=map(int,input().split())
s=sum(l)
if(s%5==0 and s!=0):
	print(int(s/5))
else:
	print("-1")
