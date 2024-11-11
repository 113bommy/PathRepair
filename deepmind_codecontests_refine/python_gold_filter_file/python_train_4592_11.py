n = int(input())
import math
for i in range(n):
    a,b = map(int,input().split())
    s = a - b
    m = a + b
    count = 0
    for i in range(1,int(math.sqrt(m)+1)):
        if m % i == 0:
            count += 2
    if s == 1 and count == 2:
        print("YES")
    else:
        print("NO")
        