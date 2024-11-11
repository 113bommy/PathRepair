sad, cnt = 0 , 0
n, cnt = map(int, input().split())
for _ in range(n):
    c, k = input().split()
    k = int(k)
    if c == '+':
        cnt += k
    elif k <= cnt:
        cnt -= k
    else:
        sad += 1
print(cnt, sad)