import collections
n,k = map(int, input().split())
a = list(map(int, input().split()))

c = collections.Counter(a).most_common()[::-1]
p = len(c) - k
if p <= 0:
  print(0)
else:
  print(sum(list(map(lambda x:x[1], c[:p]))))