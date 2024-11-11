from sys import exit
w, m = map(int, input().split())
if w in (2, 3):
    print('YES')
    exit()

while True:
    if m in (0, 1):
        print('YES')
        exit()
    prev = 1
    cur = w
    while cur < m:
        prev = cur
        cur *= w
    if cur == m:
        print('YES')
        exit()
    sum1k = (cur - 1) // (w - 1)
    if sum1k < m < cur - sum1k:
        print('NO')
        exit()
    m = min(m - prev, cur - m)
