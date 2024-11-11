n,m,k=map(int,input().split())
mod = 998244353
nCi = [1]#n-1からi個えらぶ場合の数
for i in range(n):
  next = nCi[i]*(n-1-i)*pow(i+1,mod-2,mod)
  next %= mod
  nCi.append(next)
#print(nCi)
ans = 0
for i in range(k+1):
  ans += m*pow(m-1,n-i-1,mod)*nCi[i]
  ans %= mod
print(ans)