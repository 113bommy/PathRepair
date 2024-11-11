a,b = map(int,input().split())

if a+b==2:
  print(1000000)
else:
  ans =0
  if a<=3:
    ans+= (4-a)*100000
  if b<=3:
    ans+= (4-b)*100000
  print(ans)

