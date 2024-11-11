import bisect
t=int(input())
for _ in range(t):
    n,w=list(map(int,input().split()))
    l=list(map(int,input().split()))
    a=[]
    for i in range(n):
        a.append([l[i],i])
    a.sort()
    s=[0]*(n+1)
    for i in range(1,n+1):
        s[i]=s[i-1]+a[i-1][0]
    ans=[]
    for i in range(n):
        j=bisect.bisect_right(s,s[i]+w)
        if s[j-1]>=s[i]+w//2 +w%2:
            for x in range(i,j-1):
                ans.append(a[x][1]+1)
            break
    if ans==[]:
        print(-1)
    else:
        ans.sort()
        print(len(ans))
        print(*ans)