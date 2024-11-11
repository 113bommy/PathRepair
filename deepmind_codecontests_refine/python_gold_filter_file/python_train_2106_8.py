t=int(input())
for _ in range(t):
    n,m=list(map(int,input().split()))
    mx,mn=m,m
    c=[]
    for _ in range(n):
        c.append(list(map(int,input().split())))
    ans="YES"
    prev=0
    for i in range(n):
        t,l,h=c[i]
        mx=mx+t-prev
        mn=mn-(t-prev)
        # print(mx,mn)
        if mx<l or mn>h:
            ans="NO"
            break
        mx=min(mx,h)
        mn=max(mn,l)
        # print(mx, mn)
        prev=t
    print(ans)
