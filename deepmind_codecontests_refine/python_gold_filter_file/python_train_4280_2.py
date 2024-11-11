lectura=lambda:map(int, input().split())
nVertices, nEdges= lectura()
array1= [[] for i in range(nVertices + 1)]
array2=[]
for i in range(0, nEdges):
    x, y= lectura()
    array1[x].append(y)
    array1[y].append(x)
def DFS(x):
    array2.append(x)
    for y in array1[x]:
        if (y not in array2):
            DFS(y)
DFS(1)
if(nVertices!=nEdges):
    conclusion="NO"
else:
    if(len(array2)==nVertices):
        conclusion="FHTAGN!"
    else:
        conclusion="NO"
print(conclusion)