#解説参照
n=int(input())
*a,=map(int, input().split())
*b,=map(int, input().split())
shift=0
from bisect import bisect_right,bisect_left
from collections import Counter
sb=Counter(b)
sa=Counter(a)
for bi in sb:
    if bi in sa:
        if sa[bi]+sb[bi]>n:
            print("No")
            exit()
for bi in sb:
    lb=bisect_left(b,bi)
    ra=bisect_right(a,bi)
    if a[ra-1]==b[lb]:
        shift=max(shift,ra-lb)
ans=[b[(i-shift)%n] for i in range(n)]##
print("Yes")
print(*ans)