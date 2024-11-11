n,m=map(int,(input().split()))
pairs=[]
for i in range (m):
    p1,p2=map(int,input().split())
    pairs.append((p1,p2))
x0=pairs[0][0]
y0=pairs[0][1]
restx=list(filter(lambda x: x0 not in x,pairs))
resty=list(filter(lambda x: y0 not in x,pairs))
if len(restx)==0 or len(resty)==0:
    print('YES')
    exit()
else:
    x0=restx[0][0]
    y0=restx[0][1]
    x1=resty[0][0]
    y1=resty[0][1]
    restx0=list(filter(lambda x: x0 not in x,restx))
    resty0=list(filter(lambda x: y0 not in x,restx))
    restx1=list(filter(lambda x: x1 not in x,resty))
    resty1=list(filter(lambda x: y1 not in x,resty))
if len(restx0)==0 or len(resty0)==0 or len(restx1)==0 or len(resty1)==0:
    print('YES')
else:
    print('NO')
