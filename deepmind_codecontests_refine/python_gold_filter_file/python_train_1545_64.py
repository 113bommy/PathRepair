b = [input() for i in range(int(input()))]
r = [input() for i in range(int(input()))]
o = 0
for w in list(set(b)):
  o = max(o, b.count(w) - r.count(w))
  
print(o)