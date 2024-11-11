from collections import Counter

n = int(input())
s = input()
mod = 10 ** 9+7
a = Counter(s)
ans = 1

for v in a.values():
    ans *= (v+1)

print((ans-1)%mod)