import sys
input = lambda: sys.stdin.readline().rstrip()
m=2**150-1
n=int(input())
ss=[input()[::-1]for _ in range(n)]
ss.sort(key=len)
d={}
ans=0
for s in ss:
  a=ord(s[-1])-97
  r=1
  h=0
  y=[0]*26
  for t in s[:-1]:
    b=ord(t)-97
    if h in d:
      for i in range(26):y[i]+=d[h][i]
    ans+=y[b]
    y[b]=0
    h=(h*71+b+135)&m
  ans+=y[a]
  if h not in d:d[h]=[0]*26
  d[h][a]+=1
print(ans)