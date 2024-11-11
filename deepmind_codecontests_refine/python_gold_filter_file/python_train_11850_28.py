n,m = map(int,input().split())
ans = 0
for i in range(1,int(m**0.5)+1):
  if m % i == 0 and m // i >= n:
    ans = max(ans,i)
  if m % i == 0 and i >= n:
    ans = max(ans,m//i)
print(ans)