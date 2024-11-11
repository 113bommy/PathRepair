n,m,k=map(int,input().split())
h=[int(i) for i in input().split()]
bone_at=1 
hole=0 
from collections import Counter 
c=Counter(h)
if c[1]:
    print(1)
    exit()
for i in range(k):
    u,v=map(int,input().split())
    if hole:
        continue
    elif bone_at==u and c[v]:
        hole=1 
        hole_ans=v
    elif bone_at==u:
        bone_at=v
    elif bone_at==v and c[u]:
        hole=1 
        hole_ans=u 
    elif bone_at==v:
        #print('hi')
        #print(v)
        bone_at=u
if hole:
    print(hole_ans)
else:
    #print('hi')
    print(bone_at)