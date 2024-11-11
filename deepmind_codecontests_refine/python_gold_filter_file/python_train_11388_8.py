from collections import Counter
import math
n = int(input())
c = Counter([x for x in input().split()])
if n==1:
    print("YES")
else:
    if len(c)>=2:
        for x in c:
            if c[x]>math.ceil(n/2):
                print("NO")
                break
        else:
            print("YES")
    else:
        print("NO")