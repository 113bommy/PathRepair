X,Y = map(int,input().split())
total = 0

if X <= 3:
  total += (4 - X) * 100000
if Y <= 3:
  total += (4 - Y) * 100000
if X==1 and Y==1:
  total += 400000
  
print(total)