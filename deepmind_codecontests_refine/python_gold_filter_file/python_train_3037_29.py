def ii():
  return int(input())
def ss():
  return [x for x in input()]
def si():
  return [int(x) for x in input().split()]
def mi():
  return map(int, input().split())

a = ii()
s = si()
q = ii()
ss = [0]
its = 0
for i in s:
  its += i
  ss.append(its)
for i in range(q):
  l, r = [int(x) - 1 for x in input().split()]
  print((ss[r + 1] - ss[l]) // 10)