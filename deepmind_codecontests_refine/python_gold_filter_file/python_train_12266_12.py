from fractions import gcd

N, X = map(int, input().split())
x = list(map(int, input().split()))
ans = max(x) - X

for a in x:
    ans = gcd(ans, abs(a-X))
print(ans)