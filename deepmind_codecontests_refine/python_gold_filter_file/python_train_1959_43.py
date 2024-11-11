from math import gcd
n = int(input())
a = list(map(int,input().split()))
ans = a[0]
for i in a[1:]:
    ans = gcd(ans,i)
print(ans)