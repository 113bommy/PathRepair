n=input().split()
s=input()
for i in range (int(n[1])):
	j=list(input().split())
	l=[]
	for o in range (int(j[0]),int(j[1])+1):
		if s[o-1]==j[2]:
			l.append(int(o-1))
	h=s
	s=[]
	for p in range (int(n[0])):
		if l.count(p)==1:
			s.append(j[3])
		else:
			s.append(h[p])
print(*s,sep="")