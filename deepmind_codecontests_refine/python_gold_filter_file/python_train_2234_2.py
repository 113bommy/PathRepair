import math
n, m = [int(x) for x in input().split()]
for i in range(math.ceil(n/2), n+1):
    flag = True
    if i % m == 0:
        flag = False
        print(i)
        break
if flag:
    print(-1)

