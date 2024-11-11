n=int(input())
a=list(map(int,input().split()))
d={}
for i in a:
    d[i]=d.get(i,0)+1
th=0
tw=0
p1='sjfnb'
p2="cslnb"
for i in d.keys():
    if d[i]>=3:
        th+=1
    elif d[i]==2:
        tw+=1
cp=p1
if th>0 or tw>1:
    exit(print(p2))
if tw==1:
    for i in d.keys():
        if d[i]==2:
            x=i
            break
    if x-1 in d.keys() or x==0:
        exit(print(p2))
    else:
        a[a.index(x)]=x-1
        cp=p2
a.sort()
for i in range(n):
    x=a[i]-i
    if x%2==1:
        if cp==p2:
            cp=p1
        else:
            cp=p2
if cp==p1:
    print(p2)
else:
    print(p1)
    