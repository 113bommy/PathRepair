import math
t = int(input())

for _ in range(t):
   n,x,y,d = map(int, input().split(" "))
   if x == y:
      print(0)
   else:
      if abs(x-y)%d == 0:
         print(int(abs(x-y)/d))
      elif y == n:
         print(math.ceil((n-x)/d))
      elif y == 1:
         print(math.ceil((x-1)/d))
      else:
         if (y-1) % d == 0:
            res1 = (math.ceil((x-1)/d) + int((y-1)/d))
         else:
            res1 = -1
         
         if (n-y) % d == 0:
            res2 = (math.ceil((n-x)/d) + int((n-y)/d))
         else:
            res2 = -1
            
         if res1 > 0 and res2 > 0:
            print(min(res1,res2))
         elif res1 < 0:
            print(res2)
         elif res2 < 0:
            print(res1)
            
