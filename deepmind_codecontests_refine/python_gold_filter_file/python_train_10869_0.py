n=int(input())
m=list(map(int,input().split()))
l=[]
for i in range(n-1):
	l.append(abs(m[i]-m[i+1]))
l.append(abs(m[0]-m[n-1]))
j=l.index(min(l))
# print(l)
if j==n-1:
	print(n,1)
else:
	print(j+1,j+2)	
		