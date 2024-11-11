N=int(input());p=[[]for _ in range(N+1)]
for _ in range(N-1):u,v,w=map(int,input().split());p[u].append((v,w));p[v].append((u,w))
s=[(1,0)];l=[-1]*N
while s:
 a,w=s.pop()
 l[a-1]=w%2
 for b,c in p[a]:
  if l[b-1]==-1:s.append((b,w+c))
for i in l:print(i)
