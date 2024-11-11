# cook your dish here
n,k=map(int,input().split())
l=list(map(int,input().split()))
r=[]
for i in range (n):
	if(len(r)<k and False==(l[i] in r)):
		r.insert(0,l[i])
	elif(len(r)==k and False==(l[i] in r)):
		r.pop()
		r.insert(0,l[i])
print(len(r))
print(*r, sep=' ')			
