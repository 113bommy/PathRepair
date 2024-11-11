l1, r1, l2, r2, k = map(int,input().split())
maxd = 0
if l1 <= l2 <= r2 <= r1 or l2 <= l1 <= r1 <= r2:
    if r2 <= r1:
        if l2 <= k <= r2:
            maxd = r2 - l2
        else:
            maxd = r2 - l2 + 1
    else:
        if l1<=k<=r1:
            maxd = r1 - l1
        else:
            maxd = r1 - l1 + 1
    print(maxd)
        
elif l1 <= l2 <= r1 <= r2 or l2 <= l1 <= r2 <= r1:
    if r1 <= r2:
        if l2<=k<=r1:
            maxd = r1 - l2
        else:
            maxd = r1 - l2 + 1
    else:
        if l1<=k<=r2:
            maxd = r2 - l1
        else:
            maxd = r2 - l1 + 1
    print(maxd)
else:
    print(maxd)