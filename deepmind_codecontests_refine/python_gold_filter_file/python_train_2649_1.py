a,b=map(int,input().split())
l=list(map(int,input().split()))
l=sorted(l)
c=int(b)
tot=0
d=0
for i in range(a):
        if c>0:
                tot+=l[i]*c
        elif c<1:
            break
        c-=1
if a<=b:
    print(tot)
else:
    d=(l[b:])
    print(sum(d)+tot)


