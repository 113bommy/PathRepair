N = int(input())
ans = 'No'
for i in range(N+1):
  if i % 4 == 0 and (N - i) % 7 == 0:
    ans = 'Yes'
 
print(ans)
