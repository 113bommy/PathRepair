n = int(input())
for x in range(n):
   l,r,d = map(int,input().split())
   if l <= d:
      x = (r//d +1)*d
   else:
      x = d
   print(x)
   