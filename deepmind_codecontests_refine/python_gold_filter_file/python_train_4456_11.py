from itertools import combinations

n = int(input())
r = range(n)
a = [([], []) for _ in r]
for i in r:
  for _ in range(int(input())):
    x, y = map(int, input().split())
    a[i][y].append(x - 1)

fail = lambda x: not all(x.isdisjoint(a[i][0]) and x.issuperset(a[i][1]) for i in x)

while all(map(fail, map(set, combinations(r, n)))):
  n -= 1
print(n)
