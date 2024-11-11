import sys
n=int(input())
s=input()
pfs=[[0 for _ in range(n+1)]for _ in range(26)]
for i in range(n):
  ch=ord(s[i])-ord('a')
  for  j in range(26):
    if j==ch:pfs[j][i+1]=pfs[j][i]+1
    else:pfs[j][i+1]=pfs[j][i]
#print(pfs)
dp=[[0 for _ in range(n+1)]for _ in range(26)]
for  c in range(26):
  for  l in range(n+1):
    for  r in range(l,n+1):
      tc=r-l-(pfs[c][r]-pfs[c][l])
      dp[c][tc]=max(dp[c][tc],r-l)
  for i  in range(1,n+1):
    dp[c][i]=max(dp[c][i],dp[c][i-1])

#print(dp)
A=[]
for q in range(int(input())):
  m,c=sys.stdin.readline().split()
  m=int(m)
  c=ord(c)-ord('a')
  ans=dp[c][m]
  A.append(ans)
for i in A:
  print(i)
