n,k=map(int,input().split())
A=list(map(int,input().split()))
F=list(map(int,input().split()))
A.sort(reverse=True)
F.sort()
ng=-1
ok=10**12
while ok-ng>1:
    mid=(ok+ng)//2
    temp=0
    flag=0
    for i in range(n):
        a=mid//F[i]
        if a>A[i]:
            continue
        else:
            temp+=A[i]-a
    if temp>k:
        flag=1
    if flag:
        ng=mid
    else:
        ok=mid

print(ok)