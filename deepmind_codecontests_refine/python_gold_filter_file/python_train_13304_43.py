L, R = map(int,input().split())

R = min(R, L+673)
ans = 2018
for i in range(L, R+1):
  for j in range(i+1, R+1):
    ans = min(ans, i*j%2019)
print(ans)