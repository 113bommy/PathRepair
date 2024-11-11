R,G,B,N=map(int,input().split())
ans=0
for i in range(N+1):
	for j in range (N+1):
		z=N-(R*i+G*j)
		if z>=0 and z%B==0:
			ans+=1
print(ans)			

