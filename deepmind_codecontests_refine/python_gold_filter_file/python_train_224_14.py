t=int(input())
for _ in range(t):
    n=int(input())
    a=[]
    mir=1e13
    mal=0
    for _ in range(n):
        l,r=map(int,input().split())
        mal=max(mal,l)
        mir=min(mir,r)
    #print(mal,mir)
    print(max(mal-mir,0))

