V=0
E=0
edge=[]
p=[]
rank=[]
answer=0
count=0

def makeset(x):
    p[x] = x
    rank[x] = 0
    
def union(x,y):
    link(findset(x),findset(y))
    
def link(x,y):
    if rank[x] > rank[y]:
        p[y] = x
    else:
        p[x] = y
        if rank[x] == rank[y]:
            rank[y] = rank[y] + 1
            
def findset(x):
    if x != p[x]:
        p[x] = findset(p[x])
    return p[x]
            
def takeThird(elem):
    return elem[2]
v,e = map(int,input().split())
V=v
E=e
while True:
    try:
        s,t,w = map(int,input().split())
    except:
        break
    else:
        edge.append([s,t,w])
        
edge.sort(key=takeThird)
for i in range(V):
    p.append(None)
    rank.append(None)
for i in range(V):
    makeset(i)
for i in range(len(edge)):
    if count == V-1:
        break
    if findset(edge[i][0]) == findset(edge[i][1]):
        continue
    union(edge[i][0],edge[i][1])
    answer+=edge[i][2]
    count+=1
    
print(answer)
