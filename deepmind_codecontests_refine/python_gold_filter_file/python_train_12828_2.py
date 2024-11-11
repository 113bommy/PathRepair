def worst():
   u = n-y
   l = x-1
   if u<=l: return n
   return n-u+l

def best():
   sc = x+y
   l = sc+1-n
   if l<=1: return 1
   if x==y and x==n: return l-1
   return l

for _ in range(int(input())):
   n, x, y = map(int, input().split())
   if x>y: x, y = y, x
   print(best(), worst())
