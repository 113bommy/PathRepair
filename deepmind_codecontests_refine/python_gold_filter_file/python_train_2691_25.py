import math
n,a,b = map(int,input().split())
H = list(int(input()) for _ in range(n))
l,r = 0, 10**9
d = a-b
while r-l>1:
    mid = (r+l)//2
    tmp = 0
    for h in H:
        if h <= mid*b:
            continue
        tmp += math.ceil((h-mid*b)/d)
    if tmp <= mid:
        r = mid
    else:
        l = mid
print(r)