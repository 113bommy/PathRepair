n,e = map(int,input().split())
d = list(map(int,input().split()))
ind=d.index(max(d))
maxs=d[ind]
q=[]
while True:
    if d[0]>d[1]:
        q.append((d[0],d[1]))
        r=d.pop(1)
        d.append(r)
    else:
        q.append((d[0],d[1]))
        t=d.pop(0)
        d.append(t)
    if d[0]==maxs:
        break
for _ in range(e):
    f = int(input())
    if f<=len(q):
        print(*q[f-1])
    else:
        p=f-len(q)
    
        i = p%(n-1)
     
        if i==0:
            print(d[0],d[n-1])
        else:
            
            print(d[0],d[i])