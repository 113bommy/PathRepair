W,H,x,y=map(int,input().split())
S=W*H/2
ans=0
if x==W/2 and y==H/2:
  ans=1

print(S,ans)
