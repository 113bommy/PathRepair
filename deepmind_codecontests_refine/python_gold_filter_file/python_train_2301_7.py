from math import ceil

n, k = map(int, input().split())

a = list(map(int, input().split()))

cnt = [0] * 101
mx = 0

for x in a:
    cnt[x] += 1
    if cnt[x] > cnt[mx]:
        mx = x
prib = 0
for x in cnt:
    if x:
        prib += 1

d = int(ceil(cnt[mx] / k))
print(d * k * prib - n)
