n,s = map(int, input().split())
a = list(map(int, input().split()))

def check(m):
    ac = sorted([a[i-1] + i*m for i in range(1,n+1)])
    w = sum(ac[:m])
    if w <= s:
        return True, w
    else:
        return False, 0

l,r = 0, len(a) + 1
last = -1
lastw = 0
while l < r:
    m = l + (r - l)//2
    st, w = check(m)
    if st:
        last = m
        lastw = w
        if l == m:
            break
        l = m
    else:
        r = m
print(last, lastw)