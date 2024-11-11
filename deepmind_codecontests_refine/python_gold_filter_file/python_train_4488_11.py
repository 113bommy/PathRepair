n,k=map(int,input().split())
a=str(input())
d={}
for i in a:
    if i in d:
        d[i]+=1
    else:
        d[i]=1
if len(d)!=k:
    print(0)
else:
    mini=1000000
    for j in d:
        if d[j]<mini:
            mini=d[j]
    print(mini*len(d))
