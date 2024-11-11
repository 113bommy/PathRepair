import sys

n=int(sys.stdin.readline().strip())

a={}
b=[]
while n>0:
	n-=1
	s=sys.stdin.readline()
	t=s.strip().split()
	name=t[0]
	score=int(t[1])
	b.append((name,score))
	if not name in a:
		a[name] = score
	else:
		a[name] += score

l = sorted(a.items(), key=lambda f:f[1],reverse=True)

same=set()
name = l[0][0]
score = l[0][1]
same.add(name)

for x,y in l:
	if y==score:
		same.add(x)
	else:
		break

c={}
for i in same:
	c[i]=0
for x,y in b:
	if x in same:
		c[x] += y
		if c[x]>=score:
			print(x)
			break