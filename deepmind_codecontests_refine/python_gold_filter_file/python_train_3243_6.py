n,q,p=map(int,input().split())
l=list(map(int,input().split()))
#print(len(l))
count=0
i=0
b=q
a=p
if p==0:
	print(q)
	exit()
elif q==0:
	print(p)
	exit()
while(i<n):
	
	if l[i]==1:
		if a<p and b>0:
			b-=1
			count+=1
			a+=1
		elif a==p and b>0:
			a-=1
			count+=1
		elif a>0:
			a-=1
			count+=1
		else:
			print(count)
			exit()
	else:
		if a>0:
			a-=1
			count+=1
		elif b>0:
			b-=1
			count+=1
		else:
			print(count)
			exit()
	i+=1
print(min(count,n))