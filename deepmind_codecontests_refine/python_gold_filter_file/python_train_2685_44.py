from fractions import gcd
import sys

n, m = map(int, input().split())
a = list(map(int, input().split()))
a = [i // 2 for i in a]

cnt = 1
min_a = min(a)
while min_a % 2 == 0:
    cnt *= 2
    min_a = min_a // 2

ans = 1
for i in a:
    if (i // cnt) % 2 == 0:
        print(0)
        sys.exit()
    ans = (ans * i) // gcd(ans, i)

print((m//ans+1)//2)
