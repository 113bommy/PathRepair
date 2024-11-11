n = int(input())

hh, xx = [], []
for _ in range(n):
    x, h = [int(k) for k in input().split()]
    xx.append(x)
    hh.append(h)

ans = 2 if n > 1 else 1

i = 1
taken = 0
prev_x = xx[0]
while i < len(hh) - 1:
    x = xx[i]
    h = hh[i]

    next_x = xx[i + 1]
    if h < x - prev_x - taken:
        # print("left", i)
        ans += 1
        taken = 0
    elif h < next_x - x:
        # print("right", i)
        ans += 1
        taken = h
    else:
        # print("not cut", i)
        taken = 0

    prev_x = x
    i += 1


print(ans)
