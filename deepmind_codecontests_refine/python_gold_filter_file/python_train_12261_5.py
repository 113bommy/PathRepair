s = input().split('S')

ans = 0

for i in s:
  if len(i) > ans:
    ans = len(i)
    
print(ans)
