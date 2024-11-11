n,a,b=map(int,input().split())
s=list(map(int,input().split()))
sk=s[0]*a/b
t=s[0]
del s[0]
s.sort()
ans=1
i=0
if sum(s)+t<=sk:
    print(0)
else:
    while t<=sk:
        if t+s[i]>sk:
            break
        ans+=1
        t+=s[i]
        i+=1
    print(n-ans)
