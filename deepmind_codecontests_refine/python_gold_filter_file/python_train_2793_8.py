K=int(input())
A=list(map(int,input().split()))

def func(num):
    for item in A:
        num=num//item*item
    return num

ans=[]
ok=10**20
ng=0

while ok-ng>1:
    mid=(ok+ng)//2
    if func(mid)>=2:
        ok=mid
    else:
        ng=mid

ans=ok

ok=10**20
ng=0

while ok-ng>1:
    mid=(ok+ng)//2
    if func(mid)>=4:
        ok=mid
    else:
        ng=mid

if func(ans)==2 and func(ng)==2:
    print(ans,ng)
else:
    print(-1)