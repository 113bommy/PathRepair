n,q = map(int, input().split())

a = list(map(int, input().split()))
k = list(map(int, input().split()))

s = a.copy()
for i in range(1, n):
    s[i] = s[i] + s[i-1]

ans = []
ck = 0
for i in range(q):
    ck += k[i]
    if ck >= s[-1]:
        ans.append(str(n))
        ck = 0
    else:
        l = 0
        h = n-1
        while l < h:
            m = (l+h) // 2
            if s[m] > ck:
                h = m
            else:
                l = m+1
        ans.append(str(n-l))

print('\n'.join(ans))
