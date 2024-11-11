n, k = map(int, input().split())

r = 0
while k ** r <= n:
  r +=1
print(r)