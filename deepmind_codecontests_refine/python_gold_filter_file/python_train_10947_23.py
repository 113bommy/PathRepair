def solve(n):
     c = 0
     while n != 1:
          if n % 2 == 0:
               n //= 2
               c += 1
          elif n % 3 == 0:
               n //= 3
               c += 2
          elif n % 5 == 0:
               n //= 5
               c += 3
          else:
               return -1
     return c
t = int(input())
while t:
     n = int(input())
     print(solve(n))
     t -= 1
          