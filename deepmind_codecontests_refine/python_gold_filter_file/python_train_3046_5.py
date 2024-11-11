import sys
import math
from collections import Counter

# n = int(input())
# a = list(map(int, input().split()))

t = int(input())
for _ in range(t) :
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = sorted(k - i % k for i in a if i % k != 0)
    i = 0
    x = 0
    while i < len(b) :
        count = 1
        while i + 1 < len(b) and b[i + 1] == b[i] :
            count += 1
            i += 1
        x = max(x, b[i] + (count - 1) * k)
        i += 1
    print(x + 1 if x > 0 else 0)

    

    





    









    


