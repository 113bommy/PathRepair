n = int(input())

s = input()
x = 0
ans = 0
for c in s:
  if c=='I':
    x+=1
    ans = max(x,ans)
  else:
    x-=1
print(ans)