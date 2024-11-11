def gsbsl(s):
	lbl=[]
	ssl=set()
	for c in s:
		if c.isupper():
			lbl.append(c.lower())
		else:
			ssl.add(c)
	return lbl,list(ssl)

def gtisw(txt,sw):
	for c in txt:
		if c.lower() not in sw:
			return 0
	return 1

def force(ssl,lsl,lbl,sw):
	if not gtisw(txt,sw):
		return -1
	if len(ssl)==0 and len(lbl)>0:
		return -1
	t=0
	for c in lbl:
		if c not in ssl:
			t+=1 
	return t
	
def gltrb(h,w,z,x,rad):
	l=x-rad
	if l<0:
		l=0
	r=x+rad+1
	if r>w:
		r=w
	t=z-rad
	if t<0:
		t=0
	b=z+rad+1
	if b>h:
		b=h
	slt=set()
	for c in range(t,b):
		for d in range(l,r):
			if ((c-z)**2+(d-x)**2)**.5<=rad:
				slt.add(v[c][d])
	return slt
	
def  gsctl(ssl,h,w,v,l):
	for c in range(h):
		for d in range(w):
			if v[c][d]=='S':
				ssl.update(gltrb(h,w,c,d,l))
	if 'S' in ssl:
		ssl.remove('S')
	return ssl

h,w,l=[int(x) for x in input().split(' ')]
v=[]
sw=set()
for c in range(h):
	v.append(input())
	for x in v[c]:
		sw.add(x)
input()
txt=input()
lbl,lsl=gsbsl(txt)
ssl=set()
ssl=gsctl(ssl,h,w,v,l)
print(force(ssl,lsl,lbl,sw))