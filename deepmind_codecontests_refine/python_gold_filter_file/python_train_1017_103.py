n,k,s=map(int,input().split())
if s==10**9:
  ret=[s]*k+[1]*(n-k)
else:
  ret=[s]*k+[10**9]*(n-k)
print(*ret)
