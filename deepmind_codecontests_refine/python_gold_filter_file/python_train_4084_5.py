n = int(input())
a = list(map(int, input().split()))
suf = [0]*(n+1)
for q in range(n-1, -1, -1):
    suf[q] = suf[q+1] | a[q]
naw, ans = 0, [-1, -1]
for q in range(n):
    w = a[q] & (~(naw | suf[q+1]))
    if w > ans[0]:
        ans = [w, q]
    naw |= a[q]
print(a[ans[1]], *a[:ans[1]], *a[ans[1]+1:])
