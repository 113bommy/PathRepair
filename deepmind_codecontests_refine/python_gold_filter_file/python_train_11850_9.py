n, m = list(map(int, input().split()))
d = m//n+1
for x in range(d)[::-1]:
  if m%x==0:
    break
print(x)
