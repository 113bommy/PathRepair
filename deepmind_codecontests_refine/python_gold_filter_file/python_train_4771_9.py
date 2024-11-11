N = int(input())
ans = N
    
for i in range(N+1):
  t = i
  cc = 0
  while t > 0:
    cc += t % 6
    t = t // 6
  t = N - i
  while t > 0:
    cc += t % 9
    t = t // 9
    
  ans = min(cc,ans)

print(ans)