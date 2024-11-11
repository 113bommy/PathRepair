n=int(input())
l=list(input())
p=[]
for i in range(n-2,-1,-2):
	p.append(l[i])
	l.pop(i)
for i in range(len(l)):
	p.append(l[i])
s="".join(p)
print(s)
