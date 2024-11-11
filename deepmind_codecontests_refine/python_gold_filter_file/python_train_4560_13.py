n,k = map(int,input().split())
a = list(map(int,input().split()))
f = list(map(int,input().split()))
a.sort()
f.sort(reverse=True)
ok = max(a)*max(f)
ng = -1

while ok-ng > 1:
    mid = (ok+ng)//2
    t = 0
    for i in range(n):
        t += max(0,a[i]-int(mid/f[i]))
    if t > k:
        ng = mid
    else:
        ok = mid

print(ok)