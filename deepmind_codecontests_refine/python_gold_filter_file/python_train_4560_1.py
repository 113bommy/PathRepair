N, K = map(int, input().split())
*A, = map(int, input().split())
*F, = map(int, input().split())
A.sort()
F.sort(reverse=True)

def f(x):
    ans = 0
    for i,j in zip(A, F):
        ans += (i*j-x+j-1)//j if i*j-x>=0 else 0
    return ans<=K

l, r = -1, 10**18+1
while r-l>1:
    mid = (r+l)//2
    if f(mid):
        r = mid
    else:
        l = mid

print(r)