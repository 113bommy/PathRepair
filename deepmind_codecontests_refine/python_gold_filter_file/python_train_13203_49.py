for _ in range(int(input())):
  t, x, y = map(int,input().split())
  if (t+x+y)%2 + (t<x+y):
    s = 1
    break
  s = 0
print("YNeos"[s::2])
    