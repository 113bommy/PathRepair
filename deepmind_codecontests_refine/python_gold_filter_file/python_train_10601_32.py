x,y = map(int,input().split())

ans = 0
while x<=y:
  x = 2*x
  ans +=1
print(ans)