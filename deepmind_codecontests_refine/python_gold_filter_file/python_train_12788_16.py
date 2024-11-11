a,b,c,d,e,f=map(int,input().split())
w=[a*i+b*j for i in range(31) for j in range(31) if 0<a*i+b*j<=f//100]
m=max(w)*e//min(c,d)+1
s=[c*i+d*j for i in range(m) for j in range(m) if 0<c*i+d*j<=max(w)*e]
w=sorted(list(set(w)))
s=sorted(list(set(s)))
mx=0
res=(min(a,b),0)
for p in w:
	for q in s:
		if p*100+q>f or q/p>e:
			continue
		r=100*q/(100*p+q)
		if mx<r:
			mx=r
			res=(p,q)
p,q=res
print(100*p+q,q)