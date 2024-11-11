n,k=map(int,input().split())
a=list(map(int,input().split()))
f=list(map(int,input().split()))
a.sort()
f.sort(reverse=True)
ok=10**15
ng=-1
while ok-ng>1:
    check=(ok+ng)//2
    cnt=0
    for i in range(n):
        cnt+=(max(0,a[i]-check//f[i]))
    if cnt > k:ng = (ok+ng)//2
    else: ok = (ok+ng)//2
print(ok)