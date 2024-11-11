from fractions import gcd

n = int(input())
a = list(map(int,input().split()))
res = 0
for i in a:
    res = gcd(i, res)
print(res)
