N,D = map(int,input().split())

ans = 0

for _ in range(N):
  p,q = map(int,input().split())
  if p**2+q**2 <= D**2:
    ans+=1
print(ans)