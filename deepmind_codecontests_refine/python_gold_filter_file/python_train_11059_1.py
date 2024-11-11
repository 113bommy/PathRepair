n = int(input())

for i in range(n):
  jumps = list(input())
  l = 0
  r = 1
  count = 1

  while(l < len(jumps) and r < len(jumps)):
    if(jumps[l] != jumps[r]):
      if(jumps[l] == "L"):
        count = max(count, 1 + r - l)
      l = r
    r += 1

  if(jumps[l] == "L"):
    count = max(count, 1 + r - l)
      
  print(count) 