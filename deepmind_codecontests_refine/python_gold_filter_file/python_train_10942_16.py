n=int(input())
for i in range(n):
	s,a,b,c=map(int,input().split())
	k=int(s/c)
	if k<a:
		print(k)
	else:
		k=int(s/c)
		k+=int(k/a)*b
		print(k)