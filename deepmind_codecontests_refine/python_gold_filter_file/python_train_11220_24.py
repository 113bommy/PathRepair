N = input()
A = list(map(int,input().split()))
A.sort()
ans = 1
for a in A:
  ans *= a
  if ans > 10**18:
    ans = -1
    break
print(ans)
