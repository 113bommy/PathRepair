n, k = map(int, input().split())
s = input()
d1 = {} 
d2 = {}
for i, v in enumerate(s):
  if v not in d1: d1[v] = i
  d2[v] = i
order = []
for v in d1: 
  order.append((d1[v], -1))  
  order.append((d2[v], 1))  
order.sort()

cur = k
for _, v in order:
  cur += v  
  if cur < 0:
    print("YES")
    break
else:    
  print("NO")
