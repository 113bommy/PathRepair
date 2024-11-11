n,k = list(map(int,input().split()))
n = int(n)
k = int(k)
l1 = []
l = list(map(int,input().split()))
for i in range(len(l)):
	if(l[i] not in l1):
		if(len(l1) == k):
			del l1[0]
			l1.append(l[i])
		else:
			l1.append(l[i])
print(len(l1))
for i in range(len(l1)-1,-1,-1):
	print(l1[i],end=' ')