t=int(input())
for i in range(t):
    lm=0
    rm=10**9+1
    n=int(input())
    for j in range(n):
        l,r=[int(x) for x in input().strip().split()]
        if l>lm:
            lm=l
        if r<rm:
            rm=r
    #print(rm,lm)
    print(max(lm-rm,0))
