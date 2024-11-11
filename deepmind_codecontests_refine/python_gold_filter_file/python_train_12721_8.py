l=[0]
t=1
for i in range(0,10000):
	l1=[]
	for i in l:
		l1.append(t+i)
	l.extend(l1)
	t*=3
	if t>30000:
		break
n=int(input())
l3=[]
for i in range(0,n):
	m=int(input())
	l3.append(m)
l2=sorted(l3)
d={}
i=0
j=0
while j<n:
	if l[i]>=l2[j]:
		d[l2[j]]=l[i]
		j+=1
	else:
		i+=1
for i in l3:
	print(d[i])