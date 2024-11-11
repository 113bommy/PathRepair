X, Y = map(int,input().split())
ans = 0
while Y >= X:
  X = 2 * X
  ans += 1
print(ans)