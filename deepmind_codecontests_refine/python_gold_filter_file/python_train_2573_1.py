import collections

n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
d = collections.defaultdict(set)
kr = [-n//k] * k

for i in range(n):
  ri = a[i] % k
  kr[ri] += 1
  d[ri].add(i)

krs = [0] * k
krs[0] = kr[0]
for i in range(1, k):
  krs[i] = krs[i-1] + kr[i]

org = (krs.index(min(krs))+1)%k
cnt = sum(abs(i) for i in kr) // 2
aa = [0] * cnt
bb = [0] * cnt
ai = bi = 0

for ii in range(org, org+k):
  i = ii % k
  if kr[i] > 0:
    for _ in range(kr[i]):
      aa[ai] = i
      ai += 1
  elif kr[i] < 0:
    for _ in range(-kr[i]):
      bb[bi] = i
      bi += 1

ans = 0
for ai, bi in zip(aa,bb):
  diff = (bi-org)%k - (ai-org)%k
  ans += diff
  i = d[ai].pop()
  a[i] += diff

print(ans)
print(' '.join(map(str, a)))
