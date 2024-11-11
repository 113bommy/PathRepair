n = int(input())
s = input()
w = s.count('.')

ans = w
for i in s:
  if i =='#':
    w += 1
    
  else:
    w -=1
  ans = min(ans,w)
print(ans)
