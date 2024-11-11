import math
n,k=map(int,input().split())
l=list(map(int,input().split()))
count1=0
count2=0
for i in range(0,n):
	count2+=int(l[i]/(2*k))
	if l[i]%(2*k)>0:
		if l[i]%(2*k)<=k :
			count1+=1
		else:
			count2+=1
print(math.ceil(count1/2)+count2)
