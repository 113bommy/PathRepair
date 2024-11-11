for i in range(int(input())):
  t,x,y=map(int,input().split())
  if(t+x+y)%2+(t<x+y):
    print("No")
    exit()
print("Yes")