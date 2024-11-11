K = int(input())
a = 7%K
ans = -1
for i in range(1,10**6+1):
  if a==0:
    ans = i
    break
  a = (a*10+7)%K
print(ans)