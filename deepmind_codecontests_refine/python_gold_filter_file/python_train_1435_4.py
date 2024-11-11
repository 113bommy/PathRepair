(n,m),*e=[[*map(int, t.split())] for t in open(0)]
t=[[]for _ in range(n+1)]
for a,b in e:t[a]+=[b];t[b]+=[a]
q=[1]
a=[0]*-~n
while q:q=[a[j]==0and(a.__setitem__(j,i)or j)for i in q for j in t[i]]
print('Yes',*a[2:])
