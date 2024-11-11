n = int(input())
c = 0
for x in range(n):
          q, p = map(int,input().split())
          if q <= p - 2:
                    c += 1
print(c)
