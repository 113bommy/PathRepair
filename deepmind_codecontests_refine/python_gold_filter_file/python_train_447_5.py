l=[]
n=int(input())
for i in range(n):
	l.append(list(map(int,input().split())))
l2 = [x[:] for x in l] 
for i in range(n):
	for j in range(n):
		l[i][j]=int(l2[j][i])

c=0
for i in l2:
	for j in l:
		if sum(i)<sum(j):
			c+=1
print(c)