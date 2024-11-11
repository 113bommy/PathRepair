p,y = map(int, input().split())
for b in range(y - int(y % 2 == 0), p, -2):
    if p > 2 and b % 3 == 0:
        continue

    i = 5
    ok = True
    while i < min(int(b ** 0.5) + 1, p + 1):
        if b % i == 0 or (i+2 <= p and b % (i+2) == 0):
            ok = False
            break
        i += 6
    if ok:
        print(b)
        exit(0)
print(-1)
