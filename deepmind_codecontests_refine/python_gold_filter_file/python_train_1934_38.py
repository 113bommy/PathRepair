n=int(input())
if n==3:
  print(1)
  print(3)
else:
  t=[]
  if n%2==0:
    print(int(n/2))
    for i in range(int(n/2)):
      t.append(2)
    print(*t,sep=' ')
  else:
    print(int(n/2))
    for i in range(int(n/2)-1):
      t.append(2)
    t.append(3)
    print(*t,sep=' ')