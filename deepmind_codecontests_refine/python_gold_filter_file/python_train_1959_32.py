from math import gcd

n = int(input())
a = list(map(int, input().split()))

ans = 0
for i in a:
    ans = gcd(ans, i)
print(ans)
