n,_,*l=map(int,open(0).read().split())
c=[0]*-~n
for a,b in zip(l[::2],l[1::2]):
	c[a]^=1;c[b]^=1
print("YNEOS"[any(i for i in c)::2])