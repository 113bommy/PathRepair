import heapq
n, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
f = list(map(int, input().split()))
f.sort(reverse=True)

asum = sum(a)

def test(x):
    t = [min(a[i], x//f[i]) for i in range(n)]
    return asum - sum(t)


ng = -1
ok = 10**13
while abs(ok-ng)>1:
    mid = (ok+ng)//2
    if test(mid) <= k:
        ok = mid
    else:
        ng = mid

print(ok)
