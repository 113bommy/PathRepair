a,v=map(int,input().split())
b,w=map(int,input().split())
t=int(input())
ans="NO"
if v>w:
  if abs(b-a)/abs(w-v)<=t:
    ans="YES"
print(ans)
