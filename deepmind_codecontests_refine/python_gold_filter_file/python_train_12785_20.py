N = int(input())
F = []
for i in range(N):
  a,b = map(int,input().split())
  F.append([a+b,a,b])
F.sort(key=lambda x:x[0],reverse=True)
ans = 0
for i in range(N):
  if i%2==0:
    ans += F[i][1]
  else:
    ans -= F[i][2]
print(ans)
