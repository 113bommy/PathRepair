mx=1000000000

def solve():
  a,b,c=map(int,input().split())
  if(a>=c):
    ans1=-1
    ans2=c//a+1
  elif(c>a*b or c==a*b):
    ans1=1
    ans2=-1
  else:
    ans1=1
    ans2=c//a+1
  print(ans1,ans2)

  
  

for _ in range(int(input())):
  solve()