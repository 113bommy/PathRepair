n,s=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
sum1=0
for i in range(n-1):
	sum1+=l[i]
if sum1<=s:
	print("YES")
else:
	print("NO")