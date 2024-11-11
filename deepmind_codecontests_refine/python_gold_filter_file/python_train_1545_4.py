a = int(input())
b = list(input() for i in range(a))
c = int(input())
d = list(input() for i in range(c))
e = [0]

for s in b:
  e.append(b.count(s)-d.count(s))
else:
  print(max(e))