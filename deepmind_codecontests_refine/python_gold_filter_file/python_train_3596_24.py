n, x = map(int, input().split())

cnt = x
dis = 0

for _ in range(n):
    op, d = input().split()
    d     = int(d)
    
    if op == '+': cnt += d
    else:  # op is -
        if d <= cnt:
            cnt -= d
        else:
            dis += 1
print(cnt, dis)