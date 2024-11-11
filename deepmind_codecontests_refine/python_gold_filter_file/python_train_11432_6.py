N,X,*S=map(int,open(0).read().split())
e=enumerate
d=range(X+1)
for i,s in e(sorted(S)):d=[(t*i+d[j%s])%(10**9+7)for j,t in e(d)]
print(d[-1])