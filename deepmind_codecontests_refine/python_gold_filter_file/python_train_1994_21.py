t=int(input())
a=list(map(int,input().split()))[:t]
b=list(set(a))
b.sort()
c=[]
if len(b)>2:
    for i in range(len(b)-1):
        c.append(b[i+1]-b[i])
    if len(list(set(c)))==1 and len(b)<=3:
        print(c[0])
    elif len(b)>3:
        print(-1)
    else:
        print(-1)
elif len(b)==1:
    print(0)
else:
    if len(b)==2 and abs(b[1]-b[0])%2==0:
        print(abs(b[1]-b[0])//2)
    else:
        print(abs(b[1]-b[0]))
