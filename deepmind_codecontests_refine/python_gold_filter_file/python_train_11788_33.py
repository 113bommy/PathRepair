T=int(input())
i=0
while i<T:
    s=input()
    s=[int(x) for x in s]
    ans=0
    if sum(s)==0:
        print(0)
    else:
        t=s.index(1)
        n=len(s)
        s.reverse()
        t1=s.index(1)
        s.reverse()
        for x in s[t:n-t1]:
            if x==0:
                ans+=1
        print(ans)
    i+=1
