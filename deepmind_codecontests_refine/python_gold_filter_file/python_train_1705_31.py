n,m=  tuple(list(map(int,input().split())))


print(min(n,m)+1)
for i in range(min(n,m)+1):
	print(i,min(n,m)-i)