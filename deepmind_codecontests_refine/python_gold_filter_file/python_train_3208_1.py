N = int(input())
ans = []
for i in range(1,N+1):
  for j in range(i+1,N+1):
    ans.append(sorted([i,j]))

if N%2==1:
  for i in range(1, N//2+1):
    del ans[ans.index(sorted([i, N-i]))]
else:
  for i in range(1, N//2+1):
    del ans[ans.index(sorted([i, N-i+1]))]

print(len(ans))
[print(*a) for a in ans]