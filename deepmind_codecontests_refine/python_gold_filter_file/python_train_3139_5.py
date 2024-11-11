from math import ceil
h,n=map(int,input().split())
d=list(map(int,input().split()))
cm=[0]*n
cm[0]=d[0]
mx=cm[0]
for i in range(1,n):
    cm[i]=cm[i-1]+d[i]
    mx=min(cm[i],mx)
if mx*-1<h and cm[-1]>=0:
    print(-1)
else:
    ans=0
    if mx*-1>=h:
        for i in range(n):
            h += d[i]
            ans += 1
            if h <= 0:
                break
        print(ans)
        exit()
    if mx*-1<h:
       ans += n*ceil((h + mx)/(abs(cm[-1])))
    h = h + (ans//n)*cm[-1]
    #print(h)
    for i in range(n):
        h += d[i]
        ans+=1
        if h<=0:
            break
    print(ans)
