n, m = map(int,input().split())
cnt = 0
while n <= m:
    n = n * 3
    m = m * 2
    cnt = cnt + 1
print(cnt)