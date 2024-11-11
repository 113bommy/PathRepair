import sys
input=lambda: sys.stdin.readline().rstrip()
u,v=map(int,input().split())
if u==0 and v==0:
  print(0)
elif v<u or (v-u)%2==1:
  print(-1)
elif u==v:
  print(1)
  print(u)
else:
  Ans=[u,(v-u)//2,(v-u)//2]
  if Ans[0]+Ans[1]==Ans[0]|Ans[1]:
    Ans=[Ans[0]+Ans[1],Ans[2]]
  print(len(Ans))
  print(*Ans)

