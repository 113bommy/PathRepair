k,s = map(int,input().split())
ans = 0
for x in range(k+1):
  for y in range(k+1):
    if k >= s-x-y >= 0:

      ans += 1
print(ans)