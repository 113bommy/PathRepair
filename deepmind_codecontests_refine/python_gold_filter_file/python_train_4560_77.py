N,K = map(int,input().split())
A = list(map(int,input().split()))
F = list(map(int,input().split()))

A.sort()
F.sort(reverse=True)

def is_ok(m):
    c = 0
    for a,f in zip(A,F):
        d = m//f
        c += max(0, a-d)
        if c > K:
            return False
    return True

ok = 10**13
ng = -1
while ok-ng > 1:
    m = (ok+ng)//2
    if is_ok(m):
        ok = m
    else:
        ng = m
print(ok)