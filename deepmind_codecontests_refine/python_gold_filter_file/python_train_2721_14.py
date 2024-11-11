n = int(input())
a = map(int, input().strip().split())
p, m = 0, 0
for x in a:
    p = p + (x > 0)
    m = m + (x < 0)
if p >= n/2:
    print(1)
elif m >= n/2:
    print(-1)
else:
    print(0)