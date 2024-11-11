n,x = map(int,input().split())
l = sorted(list(map(int,input().split())))
pe = 0
for i in l:
  if x-i>=0:
    x -= i
    pe += 1
  else:
    break
if x!=0 and n==pe:
  print(pe-1)
else:
  print(pe)