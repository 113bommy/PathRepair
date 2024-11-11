def digits(n):
    l=[]
    if(n==0):
        l.append(0)
    else:
        while(n>0):
            l.append(n%7)
            n=n//7
        l.reverse()
    return l
l=input().split()
n=int(l[0])
m=int(l[1])
numh=len(digits(n-1))
numm=len(digits(m-1))
ans=0
if(numh+numm>7):
    ans=0
else:
    for i in range(n):
        for j in range(m):
            o=i
            p=j
            used=[0 for lo in range(7)]
            k=0
            while(k<numh):
                used[o%7]+=1
                o=o//7
                k+=1
            k=0
            while(k<numm):
                used[p%7]+=1
                p=p//7
                k+=1
            if(max(used)==1):
                ans+=1
print(ans)