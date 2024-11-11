def check(c):
	d={}
	for i in range(10):
		if c[i]!=0:
			if c[i] not in d:
				d[c[i]]=1

			else:
				d[c[i]]+=1

	#print(c,d)
	l=list(d.keys())
	if len(l)==1 and (l[0]==1 or (l[0]!=1 and d[l[0]]==1)):
		return True

	elif(len(l)==2):

		if (l[0]==1 and d[l[0]]==1) or (l[1]==1 and d[l[1]]==1):
			#print("flag2")
			return True
		
		elif l[0]==l[1]+1:
			if d[l[0]]==1:
				return True
			else:
				return False

		elif l[1]==l[0]+1:
			if d[l[1]]==1:
				return True
			else:
				return False

		else:
			return False

	else:
		return False

n=int(input())
l=list(map(int,input().split()))
c=[0 for _ in range(10)]
t=1
c[l[0]-1]+=1
for i in range(1,n):
	c[l[i]-1]+=1
	if check(c):
		t=i+1

print(t)