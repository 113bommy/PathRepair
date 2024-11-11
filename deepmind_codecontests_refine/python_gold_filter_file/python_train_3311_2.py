R,G,B,N = map(int,input().split())
ans = 0
for i in range(0,N//R+1):
  for j in range(0,N//G+1):
    k = N - i*R -j*G
    if k%B == 0 and k>= 0:
      ans += 1
print(ans)
