N, A, B = list(map(int, input().split()))
t = [int(input()) for x in range(N)]

ans = 0

for i in range(N):
  if t[i] < A or t[i] >= B:
    continue
  else:
    ans += 1
    
    
print(N - ans)
   


