n = int(input())
x = []
for i in range(n):
    x.append(int(input()))
x = sorted(x)
a = []
good = False
if len(x) == 0:
    a = [1, 1, 3, 3]
    good = True
elif len(x) == 1:
    a = [x[0], 3 * x[0], 3 * x[0]]
    good = True
elif len(x) == 2:
    if 4 * x[0] - x[1] > 0:
        a = [4 * x[0] - x[1], 3 * x[0]]
        good = True
elif len(x) == 3:
    if x[2] == 4 * x[0] - x[1]:
        good = True
        a = [3 * x[0]]
    elif x[2] == 3 * x[0]:
        good = True
        a = [4 * x[0] - x[1]]
    elif x[2] % 3 == 0 and x[1] == 4 * (x[2] // 3) - x[0]:
        good = True
        a = [x[2] // 3]
elif len(x) == 4:
    if (x[2] == 4 * x[0] - x[1]) and (3 * x[0] == x[3]):
        good = True

if good:
    print("YES")
    for i in a:
        print(i)
else:
    print("NO")