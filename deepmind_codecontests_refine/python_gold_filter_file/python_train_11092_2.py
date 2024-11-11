n=int(input())
w=input()
p=input().split()
b=[]
for i in range(len(w)-1):
	if w[i]=='R':
		if w[i+1]=='L':
			b.append((int(p[i+1])-int(p[i]))//2)

b.sort()
if len(b)>0:
	print(b[0])
else:
	print(-1)