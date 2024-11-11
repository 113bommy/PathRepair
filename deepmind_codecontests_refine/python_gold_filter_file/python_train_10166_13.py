p, y = list(map(int , input().split()))

if y%2 == 0:
    y -= 1

for cur in range(y, p, -2):
    maxp = min(p+1, int(y**0.5)+2)
    for k in range(3,maxp):
        if cur%k == 0:
            # print(cur, 'does not fit due to', k)
            break
    else:
        print(cur)
        exit()


print(-1)