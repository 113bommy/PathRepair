from fractions import gcd

input()
a = list(map(int, input().split()))
l = a[0]
for i in a[1:]:
    l = gcd(l,i)
print(l)
