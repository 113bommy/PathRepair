from math import ceil, log2
n, I = map(int, input().split())
data = list(map(int, input().split()))
data.sort()
needK = (I * 8) // n
distinct = len(set(data))
if needK >= ceil(log2(distinct)):
    print(0)
    exit()
pref = [0] * distinct
cur = data[0]
ind = 0
for val in data:
    if val != cur:
        ind += 1
        cur = val
    pref[ind] += 1
waste = distinct - 2**needK
bad = 0
p = waste
for i in range(p):
    bad += pref[i]
ans = bad
for i in range(p - 1, -1, -1):
    bad -= pref[i]
    bad += pref[distinct - 1 - (p - 1 - i)]
    ans = min(ans, bad)
print(ans)
