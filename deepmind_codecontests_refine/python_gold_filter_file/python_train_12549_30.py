n=int(input())
a=list(map(int,input().split()))
b=[0]*2
for i in a:
	b[i]+=1
if(b[0]==1 and b[1]>0):
	print("YES")
elif(b[0]==0 and b[1]==1):
	print("YES")
else:
	print("NO")