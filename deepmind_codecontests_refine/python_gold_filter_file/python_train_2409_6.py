n, a = int(input()), list(map(int, input().split())) + [-1]
max_a = max(a)
cnt = maxcnt = 0

for i in range(n + 1):
    if a[i] == max_a:
        cnt += 1
    else:
        maxcnt = max(cnt, maxcnt)
        cnt = 0

print(maxcnt)
