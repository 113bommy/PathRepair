H, W, h, w = map(int, input().split())

if H % h == 0 and W % w == 0:
    print('No')
    exit()

big = 1000
mul = h*w-1
print('Yes')
for y in range(1, H+1):
    arr = []
    for x in range(1, W+1):
        if y % h == 0 and x % w == 0:
            arr.append(-(big*mul+1))
        else:
            arr.append(big)
    print(' '.join(map(str, arr)))

