n,k = map(int,input().split())
a = list(map(int,input().split()))
f = list(map(int,input().split()))
a.sort(reverse=True)
f.sort()
z = list(zip(a,f))
ok = max(x*y for x,y in z)
ng = -1
while ok-ng>1:
  mid = (ok+ng)//2
  if sum(x-mid//y for x,y in z if x*y > mid) <= k:
    ok = mid
  else:
    ng = mid
print(ok)