n,w=[int(s) for s in input().split()]
a=[int(s) for s in input().split()]
b=[elem//2+elem%2 for elem in a]
if sum(b)>w:
    print(-1)
elif sum(b)==w:
    print(' '.join([str(e) for e in b]))
else:
    for i in range(len(a)):
        a[i]=[a[i],i]
    a.sort(reverse=True)
    d=w-sum(b)
    i=0
    while d>0:
        j=a[i][1]
        m=min(d,a[i][0]-b[j])
        b[j]+=m
        d-=m
        i+=1
    print(' '.join([str(e) for e in b]))