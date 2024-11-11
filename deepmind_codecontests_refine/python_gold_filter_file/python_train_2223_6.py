def find(x):
    if x!=d1[x]:
        d1[x]=find(d1[x])
    return d1[x]
n=int(input())
d1={}
d2={}
for i in range(n):
    x,y=map(int,input().split())
    if d1.get(x)==None:
        d1[x]=x
    if d2.get(y)==None:
        d2[y]=find(x)
    else:
        d1[find(d1[x])]=find(d2[y])
s=set()
for i in d1:
    s.add(find(i))
print(len(s)-1)