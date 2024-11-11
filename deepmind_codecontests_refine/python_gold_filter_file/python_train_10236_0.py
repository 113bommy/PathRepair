import sys,io,os
try:Z=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
except:Z=lambda:sys.stdin.readline().encode()
Y=lambda:map(int,Z().split())
O=[]
for _ in range(int(Z())):
    n=int(Z());wl=[];wr=[];g=[[]for i in range(n)]
    for i in range(n):x,y=Y();wl.append(x);wr.append(y)
    for i in range(n-1):u,v=Y();u-=1;v-=1;g[u].append(v);g[v].append(u)
    l=[0.0]*n;r=[0.0]*n;c=[-1]*n;p=[-1]*n;q=[0]
    while q:
        v=q.pop()
        if c[v]==-1:
            c[v]=0
            for i in g[v]:
                if i!=p[v]:p[i]=v;c[v]+=1;q.append(i)
        if c[v]==0:
            for i in g[v]:
                if i!=p[v]:
                    l[v]+=max(abs(wl[v]-wl[i])+l[i],abs(wl[v]-wr[i])+r[i])
                    r[v]+=max(abs(wr[v]-wl[i])+l[i],abs(wr[v]-wr[i])+r[i])
            c[p[v]]-=1
            if v and c[p[v]]==0:q.append(p[v])
    O.append(str(int(max(l[0],r[0]))))
print('\n'.join(O))