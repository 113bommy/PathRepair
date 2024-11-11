S, L = map(int, input().split())

d, r = {}, {}
k = 0
while L >= 2**k:
    d[2**k] = (L+2**k)//2**(k+1)
    k += 1

for i in sorted(d.keys())[::-1]:
    while i <= S and d[i]:
        S -= i
        d[i] -= 1
        r[i] = r.get(i, 0) + 1

ans = []
for i in sorted(r.keys())[::-1]:
    for j in range(d[i] + r[i] - 1, d[i]-1, -1):
        ans += [str((2*j + 1)*i)]
if S:
    print(-1)
else:
    print(len(ans))
    print(' '.join(ans))

