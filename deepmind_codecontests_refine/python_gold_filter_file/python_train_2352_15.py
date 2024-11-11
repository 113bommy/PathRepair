n,m,k = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
m = m-1

best = None
for i, p in enumerate(a):
    if(best is None or abs(i-m) < best) and p > 0 and p <= k:
        best = abs(i-m)

print(10*best)