li=[int(i) for i in input().split()]
l=[]
for i in range(li[0]):
    l.append(list(input()))
g=[[0]*li[0] for i in range(li[0])]
for i in range(li[0]):
    for j in range(li[0]-li[1]+1):
        if(all(l[i][j+x]=="." for x in range(li[1]))):
            for k in range(li[1]):
                g[i][j+k]+=1

for j in range(li[0]):
    for i in range(li[0]-li[1]+1):
        if(all(l[i+x][j]=="." for x in range(li[1]))):
            for k in range(li[1]):
                g[i+k][j]+=1

y,z=-1,-1
max=-1

for i in range(li[0]):
    for j in range(li[0]):
        if g[i][j]>max:
            max=g[i][j]
            y,z=i+1,j+1
print(y,z)


