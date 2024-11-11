n = int(input())
c = []
bs = 0
for i in range(n):
  a,b = map(int,input().split())
  bs += b
  c.append(a+b)

c.sort()

ans = -bs
for i in range(n-1,-1,-1):
  if (n-1-i)%2==0: ans += c[i]
    
print(ans)
