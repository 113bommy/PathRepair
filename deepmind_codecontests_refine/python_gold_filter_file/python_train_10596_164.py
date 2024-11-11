n,k = map(int,input().split())
i = 0
while k**i <= n:
  i += 1
print(i)