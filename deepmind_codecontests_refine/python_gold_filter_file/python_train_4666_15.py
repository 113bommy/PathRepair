li = []
for i in range(3):	
  a,b = map(int,input().split())
  li.append(a)
  li.append(b)
li.sort()
if li==[1, 2, 2, 3, 3, 4]:
  print("YES")
else:
  print("NO")