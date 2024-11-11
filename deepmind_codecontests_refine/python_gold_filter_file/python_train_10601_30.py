A, Y = map(int, input().split())
ans = 0
while A<=Y:
  ans+=1
  A*=2
print(ans)