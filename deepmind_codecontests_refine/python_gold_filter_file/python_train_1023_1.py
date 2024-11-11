N=int(input())
city=[0]*N
for i in range(N):
    x,y=map(int,input().split())
    city[i]=(i,x,y)
city.sort(key=lambda x:x[1])
data=[(city[i][0],city[i+1][0],city[i+1][1]-city[i][1]) for i in range(N-1)]
city.sort(key=lambda x:x[2])
data+=[(city[i][0],city[i+1][0],city[i+1][2]-city[i][2]) for i in range(N-1)]
data.sort(key=lambda x:x[2])
root=[-1]*N
def search(i):
    global root
    if root[i]>=0:
        root[i]=search(root[i])
        return root[i]
    return i
cost=0
for i,j,k in data:
    ri=search(i)
    rj=search(j)
    if ri==rj:
        continue
    elif root[ri]<=root[rj]:
        cost+=k
        root[ri]+=root[rj]
        root[rj]=ri
    elif root[ri]>root[rj]:
        cost+=k
        root[rj]+=root[ri]
        root[ri]=rj
print(cost)