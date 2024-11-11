h,w,k=map(int,input().split())
a=[list(input())for i in range(h)]
b=[[1]*w for i in range(h)]
c=0
for i in range(h):
    if c:
        break
    for j in range(w):
        if a[i][j]=="S":
            c=1
            p=[i,j]
            b[i][j]=0
def f(x,y):
    return min(x,w-y-1,y,h-x-1)
an=f(p[0],p[1])
q=[p]
c=0
while q and c!=k:
    c+=1
    d=[]
    x=[0,0,1,-1]
    y=[1,-1,0,0]
    for i,j in q:
        for s,t in zip(x,y):
            if 0<i+s<h-1 and 0<j+t<w-1:
                if b[i+s][j+t]:
                    if a[i+s][j+t]==".":
                        an=min(an,f(i+s,j+t))
                        b[i+s][j+t]=0
                        d.append([i+s,j+t])
            else:
                if a[i+s][j+t]==".":
                     print(1)
                     exit()
    q=d[::]
print(2+(an-1)//k)