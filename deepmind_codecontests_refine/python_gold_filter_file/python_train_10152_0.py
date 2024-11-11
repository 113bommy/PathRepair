l, r, k = map(int, input().split())
if l == r and r == k:
    print(k)
    exit(0)
i = l
if l == r and k * k == r:
    print(r)
    exit(0)
fl = 0
cnt = 1
for j in range(l, r + 1):
    if j == 1:
        print(1)
        fl = 1
    cnt *= k
    if cnt > r:
        break
    if cnt >= l and cnt <= r:
        print(cnt, ' ')
        fl = 1

if fl == 0:
    print(-1)