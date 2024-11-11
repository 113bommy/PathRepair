n=int(input())
a = [int(input()) for i in range(n)]
a.append(0)
ans = 0
tmp = 0
for i in range(n+1):
  if a[i]!=0:
    tmp += a[i]
  else:
    ans += tmp//2
    tmp = 0
print(ans)