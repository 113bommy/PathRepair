n = int(input())
s = input()
w = s.count('.')
b = 0
ans = w
for i in s:
  if i =='#':
    b += 1
    
  else:
    w -=1
  ans = min(ans,b+w)
print(ans)
