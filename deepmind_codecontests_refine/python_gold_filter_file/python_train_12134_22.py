from sys import stdin,stdout
from bisect import bisect_right as br
from bisect import bisect_left as bl
from bisect import insort_left as il
from math import gcd

n=int(stdin.readline())
lst=[int(i) for i in stdin.readline().split()]
k=1
ans=1
temp=lst[0]
for i in lst[1:]:
    if i<=temp:
        ans=max(k,ans)
        k=1
    else:
        k+=1
    temp=i
    ans=max(k,ans)
stdout.write(str(ans))
