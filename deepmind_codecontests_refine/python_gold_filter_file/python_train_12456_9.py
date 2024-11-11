n=int(input())
l=list(map(int,input().split()))
f=0
for x in range(n):
	a=l[x]
	b=l[a-1]
	c=l[b-1]
	if c==x+1 and a!=b and b!=c:
		f=1
		print("YES")
		break
if f==0:print("NO")