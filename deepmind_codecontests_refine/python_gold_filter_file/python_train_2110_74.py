p=int(input())
while(p>0):
    p-=1
    n=int(input())
    s=list(range(1,n+1))
    y=list()
    y.append(s[0])
    z=s[0]
    s[0]=0
    for x in range(0,n):
            for i in range(0,n):
                if s[i]|z>=2 and s[i]>0:
                    y.append(s[i])
                    z=s[i]
                    s[i]=0
                    break
    print(*y)
