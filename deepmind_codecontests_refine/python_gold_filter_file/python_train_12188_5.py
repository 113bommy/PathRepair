'''
????????£????????????????????????

'''

import queue
v,e,s=map(int,input().split())
edge=[]
inf =1000000100
for i in range(v):
    edge.append([])

for i in range(e):
    vs,vt,d=map(int,input().split())
    edge[vs].append((vt,d))
    
dis=[]
for i in range(v):
    dis.append(inf)

dis[s]=0

q = queue.PriorityQueue()
q.put((0,s))


while(not q.empty()):
    now=q.get()
    nowv=now[1]
    for (vt,d) in edge[nowv]:
        if dis[vt]>dis[nowv]+d:
            dis[vt]=dis[nowv]+d
            q.put((dis[vt],vt))
'''
finished=0
while(finished<v and not q.empty()):
    now=q.get()
    nowv=now[1]
    if now[0]>dis[nowv]: continue
    for (vt,d) in edge[nowv]:
        if dis[vt]>dis[nowv]+d:
            dis[vt]=dis[nowv]+d
            q.put((dis[vt],vt))
    finished+=1       
'''
for i in range(v):
    if dis[i]>=inf:
        print("INF")
    else:
        print(dis[i])