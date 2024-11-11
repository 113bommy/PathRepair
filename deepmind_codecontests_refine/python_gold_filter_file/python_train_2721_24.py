n = int(input())
a = list(map(int, input().split()))

z = b = c = 0
for i in a:
    # print(i)
    if i < 0:
        c += 1
    elif i > 0:
        b += 1
    else:
        z += 1


if b >= c and b >= int(n / 2 + 0.5):
    print(1)
elif c > b and c >= int(n / 2 + 0.5):
    print(-1)
else:
    print(0)