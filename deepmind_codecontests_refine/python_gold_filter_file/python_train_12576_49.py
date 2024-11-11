N = int(input())
A=0
B=0
BA=0
ans=0
for i in range(N):
  s = input()
  last = len(s)-1
  ans += s.count('AB')
  if s[0]=='B' and s[last]=='A':
    A+=1
    B+=1
    BA+=1
  elif s[0]=='B':
    B+=1
  elif s[last]=='A':
    A+=1
ans += min(A,B)
if A==B and B==BA and A!=0:
  ans-=1
print(ans)