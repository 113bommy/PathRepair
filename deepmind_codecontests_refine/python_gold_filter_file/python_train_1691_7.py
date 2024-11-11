import sys, inspect
ints = (int(x) for x in sys.stdin.read().split())

ntc = next(ints)
for tc in range(1, ntc+1):
  n = next(ints)
  p = [next(ints) for i in range(n)]
  h = [p[i] for i in range(n) if i==0 or p[i-1]+1!=p[i]]
  print('Yes' if sorted(h)==h[::-1] else 'No')
