n = int(input())
a = [int(i) for i in input().split()]
e = []
o = []
for i in range(n):
  if a[i] % 2 == 0:
    e.append(a[i])
  else:
    o.append(a[i])

e = sorted(e, reverse=True)
o = sorted(o , reverse = True)
# print (e , o)
l = abs(len(e) - len(o))
if l > 1:
  s = 0
  if len(e) > len(o):
    for i in range(len(o)+1 , len(e)):
      s = s + e[i]
  else:
    for i in range(len(e)+1, len(o)):
      s = s + o[i]
  print (s)
else:
  print (0)