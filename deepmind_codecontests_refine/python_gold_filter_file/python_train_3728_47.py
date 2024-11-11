x,y,z,k,*L=map(int,open(0).read().split())
a=L[:x];b=L[x:x+y];c=sorted(L[x+y:])[::-1]
ab=sorted(i+j for i in a for j in b)[::-1][:min(x*y,k)]
print(*sorted(i+j for i in ab for j in c)[::-1][:k],sep="\n")