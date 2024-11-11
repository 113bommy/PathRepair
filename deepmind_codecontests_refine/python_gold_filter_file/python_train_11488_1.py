import math
n,m,k=map(int,input().split())
q,z,y,pp={},-math.inf,[],k
for i in range(n):
    input();q[i]=[]
    for j in range(m):
        q[i].append(list(map(int,input().split())))
for i in q:
    r=[]
    for j in q:
        o=[]
        for p in range(m):
            o.append([(q[j][p][1]-q[i][p][0]),q[i][p][2]])
        r.append(o)
    y.append(r)
for i in y:
    for j in i:
        j.sort(reverse=True)
        h,k=0,pp
        for p in j:
            if p[0]>0 and k>0:h+=p[0]*min(p[1],k);k-=p[1]
        z=max(z,h)
print(z)