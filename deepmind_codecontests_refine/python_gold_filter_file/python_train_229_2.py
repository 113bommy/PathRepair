for _ in range(int(input())):
    n=int(input())
    maxp=0
    maxc=0
    ans=1
    for i in range(n):
        p,c=map(int,input().split())
        if i==0:
            maxp=p
            maxc=c
        elif p==maxp and c!=maxc:
            ans=0
        elif p-maxp<c-maxc:
            ans=0
        else:
            if p<maxp:
                ans=0
            else:
                maxp=p
            if c<maxc:
                ans=0
            else:
                maxc=c
        if c>p:
            ans=0
    print("YES" if ans is 1 else "NO")