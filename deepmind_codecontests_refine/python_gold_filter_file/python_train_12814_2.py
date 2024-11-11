from collections import defaultdict
import string

n = int(input())
x = input()
y = input()

for i in x:
    if x.count(i) != y.count(i):
        print(-1)
        exit(0)

s = ""
c = 0
for i in range(n):
    if x[0] != y[0]:
        l = x.index(y[0])
        x = x[:l] + x[l + 1:]

        for j in range(l):
            s += str(l - j + i) + " "
            c += 1

    else:
        x = x[1:]
    y = y[1:]
print(c)
if len(s) == 0:
    exit(0)
else:
    print(s)
