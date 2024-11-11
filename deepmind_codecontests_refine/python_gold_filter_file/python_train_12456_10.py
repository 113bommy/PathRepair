n=int(input())
m=list(map(int,input().split()))
l,k=[],[]
for i in range(n):
	l.append(m[i]-1)
for i in range(n):
	if(l[l[l[i]]])==i:
		k.append(1)
if sum(k)!=0:
	print("YES")
else:
	print("NO")			
