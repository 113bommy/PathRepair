n,a,b=map(int,input().split())
HP=[int(input()) for i in range(n)]
ng=0
ok=10**10
for i in range(40):
    check=(ok+ng)//2
    c=a-b
    cnt=0
    d=list(map(lambda x: x-check*b,HP))
    for j in d:
        cnt+=max(0,(j+c-1)//c)
    if check < cnt:
        ng=check
    else:
        ok=check
print(ok)
