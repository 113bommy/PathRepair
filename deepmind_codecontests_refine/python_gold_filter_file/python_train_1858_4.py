# -*- coding: utf-8 -*-
from collections import Counter

H, W = tuple(map(int, input().split()))
C = Counter()

for _ in range(H):
    C.update(input())


if H%2 == 0 and W%2 == 0:
    for v in C.values():
        if v%4 != 0:
            print("No")
            break
    else:
        print("Yes")

elif (H%2 == 1) and (W%2 == 1):
    values = list(C.values())
    v4 = [v//4 for v in values]
    l1 = [v%2 for v in values]
    if ((H-1)*(W-1)//4 <= sum(v4)) and sum(l1)==1:
        print("Yes")
    else:
        print("No")

else:
    if H%2 == 0:
        H, W = W, H
    values = list(C.values())
    v4 = [v//4 for v in values]
    l1 = [v%2 for v in values]
    if ((H-1)*(W)//4 <= sum(v4)) and sum(l1)==0:
        print("Yes")
    else:
        print("No")   