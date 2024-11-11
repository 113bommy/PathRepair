n = int(input())
a = dict()
d = []
for i in range(n):
  s = list(input().split())
  if a.get(s[0]) == None:
    a[s[1]] = s[0]
    d.append(s[0])
  else:
    r = a.pop(s[0])
    a[s[1]] = r
print(len(d))
for i in range(len(d)):
  t = a.popitem()
  print(t[1], t[0])
