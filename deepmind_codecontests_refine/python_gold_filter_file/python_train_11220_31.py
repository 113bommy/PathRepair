n = int(input())
*l, = map(int,input().split())
ans = 1
for i in l:
  ans *= i
  if ans > 10**18:
    ans = -1
    break
if 0 in l:
  ans = 0
print(ans)
