n,v=map(int,input().split())
if v>=n-1:
	print(n-1)
else:
	print(v-1+(n-v)*(n-v+1)//2)	