n=int(input())
l=list(map(int,input().split()))
l.sort()
d={0:0}
for i in l:
    try:
        k=d[i-1]
        try:
            k1=d[i]
            try:
                k=d[i+1]
            except KeyError:
                d[i+1]=0
        except KeyError:
            d[i]=1
    except KeyError:
        d[i-1]=0
print(len(d.keys())-1)