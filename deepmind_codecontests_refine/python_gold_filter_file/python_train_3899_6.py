n,v=map(int,input().split(" "))
a,b=[],[]
for i in range(n):
    x,y=map(int,input().split(" "))
    a.append(x)
    b.append(y)
fi=max(a)
li=[0]*3002
for i in range(n):
    li[a[i]]+=b[i]
ans=0
for i in range(1,3002):
    ans+=min(v,li[i-1]+li[i])
    li[i]=max(0,li[i]-max(0,v-li[i-1]))
print(ans)
