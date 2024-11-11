'''
code credits : ਜੈਲ਼ਦਾਰ 
'''
n,m=map(int,input().split())
arr=list(map(int,input().split()))
b=[]
for i in range(m):
	l,r=map(int,input().split())
	b.append([l,r])
ans=0
rt=[]
for i in range(1,n+1):
	brr=arr[:]
	temp=[]
	for j in range(m):
		if i>=b[j][0] and i<=b[j][1]:
			# print("i is",i)
			# print("l and r is ",b[j][0],b[j][1])
			continue
		temp.append(j)
		for k in range(b[j][0]-1,b[j][1]):
			brr[k]-=1
	# print(temp)
	mx=max(brr)
	mi=min(brr)
	if (mx-mi)>ans:
		rt=temp[:]
	ans=max(ans,mx-mi)
print(ans)
print(len(rt))
for i in rt:
	print(i+1,end=" ")
print()