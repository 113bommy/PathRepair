import math
p, y = input().split()
p = int(p)
y = int(y)
for i in range(y, p, -1):
    for d in range(2, min(int(math.sqrt(i))+1, p+1)):
        if i % d == 0:
            break
    else:
        print(i)
        break
else:
    print(-1)