rn = lambda: int(input())
rl = lambda: list(map(int, input().split()))
rns = lambda: map(int, input().split())
rs = lambda: input()
yn = lambda x: print('Yes') if x else print('No')

for _ in range(rn()):
    n,k=rns()
    l=rl()
    from math import ceil
    a=len(set(l))
    ans=0
    if k==1:
        if a!=1:
            ans=-1
        else:
            ans=1
    else:
        ans=1+max(0,ceil((a-k)/(k-1)))
    print(ans)