n,s=map(int,input().split())
a=list(map(int,input().split()))
m=sum(a)-max(a)
if m>s:
	print("NO")
else:
	print("YES")