N = int(input())
ans = [0 for i in range(N)]

for i in range(N-1):
  C, S, F = map(int, input().split())
  for j in range(0, i+1):
    if ans[j] < S:
      ans[j] += S - ans[j]
    elif ans[j]%F != 0:
      ans[j] += F - ans[j]%F
    ans[j] += C
    
for i in ans:
  print(i)

