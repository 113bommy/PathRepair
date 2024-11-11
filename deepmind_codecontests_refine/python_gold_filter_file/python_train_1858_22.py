from collections import Counter

h, w = (int(x) for x in input().split())
A = []
for _ in range(h):
    A += list(input())

B = [0, 0, 0]
if h % 2 == 0 and w % 2 == 0:
    B[2] += h * w
elif h % 2 == 0 and w % 2 == 1:
    B[2] += h * (w - 1)
    B[1] += h
elif h % 2 == 1 and w % 2 == 0:
    B[2] += w * (h - 1)
    B[1] += w
else:
    B[2] += (w - 1) * (h - 1)
    B[1] += w + h - 2
    B[0] += 1

i = 0
for key, value in Counter(A).most_common():
    while value >= 4 and B[2] > 0:
        B[2] -= 4
        value -= 4
    while value >= 2 and B[1] > 0:
        B[1] -= 2
        value -= 2
    while value >= 1 and B[0] > 0:
        B[0] -= 1
        value -= 1
    if value != 0:
        print("No")
        exit()
else:
    print("Yes")
    exit()
