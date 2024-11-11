n,k=map(int,input().split())
l=list(map(int,input().split()))
ln=[]
if n<=k:
	for i in range(n):
		if l[i] not in ln:
			ln.insert(0,l[i])
else:
	for i in range (n):
		if len(ln)<k:
			if l[i] not in ln:
				ln.insert(0,l[i])
		else:
			if l[i] not in ln:
				del(ln[-1])
				ln.insert(0,l[i])
print(len(ln))
for j in range(len(ln)):
	print(ln[j],end=" ")
	