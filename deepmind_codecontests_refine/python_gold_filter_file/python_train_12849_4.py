def inp():
    return map(int, input().split())


from math import *

n, m = inp()
out ,dis= -1,set()

for i in range(n):
    string = input()
    g, s = string.find('G'), string.find('S')
    if g < s:
        dis.add(s-g)
    else:
        exit(print(-1))

# print(dis)
print(len(dis))
