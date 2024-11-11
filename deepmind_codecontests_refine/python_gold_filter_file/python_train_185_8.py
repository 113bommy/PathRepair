import collections

N, P = map(int, input().split())
ans = 1

def cal(n):
  i = 2
  table = []
  while i * i <= n:
    while n % i == 0:
      n //= i
      table.append(i)
    i += 1
  if n > 1:
    table.append(n)
  return table

c = collections.Counter(cal(P)).most_common()

if N == 1:
    print(P)
elif P == 1:
    print(1)
else:
    for x, y in c:
        if y >= N:
            ans *= x**(y//N)
    print(ans)