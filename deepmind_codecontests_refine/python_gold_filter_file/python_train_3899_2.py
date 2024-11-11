n,v=map(int,input().split(" "))
a,b=[],[]
for i in range(n):
    x,y=map(int,input().split(" "))
    a.append(x)
    b.append(y)
fi=max(a)
li=[]
for i in range(fi+3):
    li.append([0,0])
for i in range(n):
    li[a[i]][1]+=b[i]
ans=0
for i in range(fi+2):
    if li[i][0]<=v:
        ans+=li[i][0]
        if li[i][1]<=v-li[i][0]:
            ans+=li[i][1]
        else:
            ans+=v-li[i][0]
            li[i+1][0]=li[i][1]-v+li[i][0]
    else:
        ans+=v
        li[i+1][0]=li[i][1]
print(ans)