from math import gcd

n = int(input())
a = list(map(int, input().split()))

# 解説AC(a*loga)
ans = 0
cnt = [0] * (max(a) + 1)
for ai in a:
    ans = gcd(ans, ai)
    cnt[ai] += 1

if ans != 1:
    print('not coprime')
elif any(sum(cnt[i::i]) > 1 for i in range(2, max(a) + 1)):
    print('setwise coprime')
else:
    print('pairwise coprime')
