R,G,B,N = map(int,input().split())
x = N//R
ans = 0
for i in range(x+1):
  M = N - i*R
  for j in range((M//G)+1):
    L = M - j*G
    if L%B == 0:
      ans += 1
print(ans)