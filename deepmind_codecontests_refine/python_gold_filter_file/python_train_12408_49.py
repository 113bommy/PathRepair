n,m=map(int,input().split())
m+=1
for i in range(n,m):
	if len(str(i))==len(set(str(i))):
		print(i)
		break
else:
	print(-1)