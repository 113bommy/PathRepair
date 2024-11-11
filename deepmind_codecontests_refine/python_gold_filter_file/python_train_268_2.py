ins = lambda : map(int, input().split())
n, k, m = ins()
c = list(ins())
c.sort()
s = sum(c)
ans = 0
for i in range(min(n, m//s)+1):
    t, a = m-s*i, i*k+i
    for j in range(k):
        for l in range(n-i):
            if t-c[j] < 0:
                break
            t -= c[j]
            a += 1
        if t-c[j] < 0:
            break
    ans = max(ans, a)
print(ans)
