x,y=map(int,input().split())
xx=min(x,y)
fact=1
for i in range(1,xx+1):
	fact*=i
print(fact)