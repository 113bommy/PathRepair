import math

n = int(input())
x = input().split()
y = []
for i in x:
    y.append(int(i))


cp = 0
cm = 0
for k in y:
    if k / 1 > 0:
        cp += 1
    if k / 1 < 0:
        cm += 1

r = math.ceil(n / 2)

if cp >= r:
    print(1)
elif cm >= r:
    print(-1)
elif not cp >= r and not cm >= r:
    print(0)
