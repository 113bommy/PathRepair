n = int(input())
s = input()
x = 0
ans = 0
for i in s:
  if i=="I":
    x+=1
    ans = max(x, ans)
  else:
    x-=1
print(ans)