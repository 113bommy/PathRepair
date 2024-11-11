read = lambda: map(int, input().split())
c, v0, v1, a, l = read()
cur = 0
cnt = 0
while cur < c:
    cur = max(0, cur - l)
    cur += min(v1, v0 + a * cnt)
    cnt += 1
print(cnt)