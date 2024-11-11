n,m=map(int,input().split())
a=tuple(map(int,input().split()))
l,r=-1,m-1
while(l+1<r):
    M=(l+r)//2
    ai1=0
    for ai in a:
        if (m-ai+ai1)%m>M:
            if ai<ai1:
                l=M
                break
            ai1=ai
    else:
        r=M
print(r)