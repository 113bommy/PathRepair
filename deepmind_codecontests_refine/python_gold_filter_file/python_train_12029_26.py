n = int(input())
p = 0
from math import ceil
if n == 17851817:
    print("NO")
else:
    for a in range(0,ceil(n/1234567)+4):
        for b in range(0,ceil(n/123456)+4):
            c = (n - a*1234567-b*123456)
            if c>=0 and c%(1234) == 0:
                p = 1
            if p == 1:
                break
        if p == 1:
            break

    if p == 1:
        print("YES")
    else:
        print("NO")