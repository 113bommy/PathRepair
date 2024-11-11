from math import ceil

x = input()

L = ["A", "H", "I", "M", "O", "T", "U", "V", "W", "X", "Y"]

N = ceil(len(x)//2)

p = True

for i in range(0, N + 1):

    if x[i] != x[-i - 1] or x[i] not in L:
        p = False
        break


if p is True:

    print("YES")

else:

    print("NO")








