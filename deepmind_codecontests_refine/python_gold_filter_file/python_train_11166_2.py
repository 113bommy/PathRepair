y=lambda s:ord(s)-97
z=lambda:list(map(y,input()))
for _ in range(int(input())):
    n=int(input())
    a,b=z(),z()
    f=0
    c=0
    for i in range(20):
        m=20
        l=[]
        for j in range(n):
            if a[j]==i:
                if b[j]<i:
                    f=1
                    break
                elif b[j]>i:
                    m=min(m,b[j])
                    l.append(j)
        if f:break
        if m==20:continue
        else:
            c+=1
            for j in l:a[j]=m
    if f:print(-1)
    else:print(c)