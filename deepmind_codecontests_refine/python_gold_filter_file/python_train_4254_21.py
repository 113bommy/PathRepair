n,m=map(int,input().split())
g=[0]*(n+1)
for _ in range(m):
  a,b=map(int,input().split())
  g[a]+=1
  g[b]+=1
  g[a]%=2
  g[b]%=2
  
print("YES" if 1-max(g) else "NO")
