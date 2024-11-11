x,y,z,t1,t2,t3=map(int,input().split())
m=(abs(x-z)*t2)+(t3*3)+(abs(x-y)*t2)
k=abs(x-y)*t1
# print(m,k)
if m<=k:
	print('YES')
else:
	print('NO')