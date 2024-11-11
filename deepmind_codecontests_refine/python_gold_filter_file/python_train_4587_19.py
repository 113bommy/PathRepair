while 1:
 n, x = map(int, input().split())
 counter = 0
 if n == 0 and x == 0:
  break
 # y + (y-1) + (y-2) = x 
 y = (x+3) // 3
 for a in range(y, n+1):
  for b in range(2, a):
   if (x-a-b) > 0 and (x-a-b) < b:
    counter += 1
 print(counter)
  