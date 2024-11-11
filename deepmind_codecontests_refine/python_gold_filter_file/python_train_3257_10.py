import bisect
t=int(input())
#???
for _ in range(t):
    n,m=map(int,input().split())
    *w,=map(int, input().split())
    wi=[(wj,j) for j,wj in enumerate(w)]
    w.sort()
    wi.sort()
    i=bisect.bisect_left(w,(m+1)//2)
    j=bisect.bisect_right(w,m)
    if j-i:
        print(1)
        print(wi[i][1]+1)##
        continue
    sw=sum(w[:i])
    if sw<(m+1)//2:
        print(-1)
    else:
        sm=0
        for x in range(i):
            sm+=w[x]
            if sm>=(m+1)//2:
                print(x+1)
                ans=[j+1 for wj,j in wi[:x+1]]
                print(*ans)
                break