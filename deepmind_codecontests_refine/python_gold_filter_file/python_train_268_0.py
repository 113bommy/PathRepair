n,k,m = list(map(int, input().split()))
t = sorted(map(int, input().split()))
st = sum(t)
res = 0
for x in range(min(m//st, n)+1):
    rem = m-x*st
    r = x*(k+1)
    # for i in range(k):
        # y = min(rem//t[i], n-x)
        # rem -= t[i]*y
        # m += y
    for i in range(k):
        for _ in range(n-x):
            if rem >= t[i]:
                rem -= t[i]
                r += 1
    res = max(res, r)
print(res)