from sys import stdin,stdout
from math import ceil
nmbr = lambda: int(stdin.readline())
lst = lambda: list(map(int,stdin.readline().split()))
p2=[1]
for i in range(1,64):
    p2+=[(p2[-1]*2)]
def sb(x):
    c=0
    while x>0:
        x=x&(x-1)
        c+=1
    return c
for _ in range(nmbr()):
    l,r=lst()
    sets=[0]*64
    for bp in range(64):
        if (r>>bp)&1:sets[bp]=1+sets[max(bp-1,0)]
        else:sets[bp]=sets[max(bp-1,0)]
    mx=sets[-1]
    # print(sets)
    init=mx
    ans=r
    for bp in range(64):
        if (r>>bp)&1:
            new=r^(p2[bp])|(p2[bp]-1)
            # if new>=l:
            #     bits=sets[-1]-sets[bp]+bp
            #     if (bits>mx) or (bits==mx and new<ans):
            #         ans=new
            #         mx=bits
            if new>=l:
                ans=new
    if sb(r)>sb(ans):print(r)
    else:print(ans)
