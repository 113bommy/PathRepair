n=int(input())
l=list(map(int,input().split()))
mx=[0]*(n+2)
mn=[0]*(n+2)
l.sort()
for i in l:
	if mx[i-1]==0:
		mx[i-1]=1
	elif mx[i]==0:
		mx[i]=1
	else:
		mx[i+1]=1
	if mn[i]==mn[i-1] and mn[i-1]==mn[i+1] and mn[i+1]==0:
		mn[i+1]=1
print(sum(mn),sum(mx))

