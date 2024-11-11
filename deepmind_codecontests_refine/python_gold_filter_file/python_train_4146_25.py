from collections import Counter

N = int(input())
A = list(map(int,input().split()))
ctr = Counter(A)
lctr = sorted(list(ctr.items()),reverse=True)

ans = 0
for k,_ in lctr:
    beki = 2**(len(bin(k))-2)
    a = beki-k
    if a == k:
        ans += ctr[k]//2
    else:
        tmp = min(ctr[k], ctr[a])
        ans += tmp
        ctr[a] -= tmp
print(ans)