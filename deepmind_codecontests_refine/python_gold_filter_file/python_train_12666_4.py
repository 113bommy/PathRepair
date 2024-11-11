def gcd(a,b):
    return a if b == 0 else gcd(b, a % b)

l,r,x,y = map(int,input().split())
from math import sqrt
if y % x !=0 :
    print(0)
    exit(0)

y = y //x
if l % x != 0 :
    l = l // x + 1
else:
    l  //= x


if r % x != 0 :
    r = r // x
else:
    r  //= x


ans = 0

bound = int(sqrt(y)) + 1
    

for i in range(1, bound + 1):
    if i > y//i:
        break
    if (gcd (i, y//i)) != 1:
        continue
    if y % i == 0:
        if (l <= i <= r) and(l <= y//i <= r):
            if i == y//i:
                ans+=1
            else:
                ans+=2

print(ans)
