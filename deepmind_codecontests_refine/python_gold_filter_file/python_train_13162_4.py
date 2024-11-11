n,v=map(int,input().split())
l=[]
l.extend(map(int,input().split()))
l.remove(max(l))
if sum(l)<=v :
  print('YES')
else :
  print('NO')
