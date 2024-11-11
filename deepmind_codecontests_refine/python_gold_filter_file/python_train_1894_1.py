from sys import stdin
import math
t=int(stdin.readline())
while t:
    n=int(stdin.readline())
    arr=list(map(int,stdin.readline().split()))
    ans='no'
    s=0
    for e in arr:
        if e<=2048:s+=e
    if s>=2048:
        ans='yes'
    print(ans)
    t-=1