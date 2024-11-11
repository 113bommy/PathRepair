a = int(input())
v,r,t,l =[],0,-1,0
for i in range(a):
	q,w= map(int,input().split())
	v.append([q,w])
	l+=q;r+=w
b = abs(l-r)
for i in range(len(v)):
	w = abs((l+v[i][1]-v[i][0])-(r+v[i][0]-v[i][1]))
	if w>b:t,b = i,w
print(t+1)