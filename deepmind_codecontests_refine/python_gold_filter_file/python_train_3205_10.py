n, m = map(int, input().split())
h = list(map(int, input().split()))
ans = [1 for i in range(n)]
for i in range(m):
  a, b = map(int, input().split())
  a -= 1
  b -= 1
  if h[a] >= h[b]:
    ans[b] = 0
  if h[b] >= h[a]:
    ans[a] = 0
    
print (sum(ans))