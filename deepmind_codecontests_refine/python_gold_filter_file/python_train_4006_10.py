(n,m,k)=[int(x) for x in input().split()]
l=[[0 for x in range(m+2)] for x in range(n+2)]
h=0
for i in range(k):
  (a,b)=[int(x) for x in input().split()]
  l[a][b]=1
  if l[a-1][b-1]+l[a-1][b]+l[a][b-1]+l[a][b]==4 or l[a+1][b+1]+l[a+1][b]+l[a][b+1]+l[a][b]==4 or l[a-1][b+1]+l[a-1][b]+l[a][b+1]+l[a][b]==4 or l[a+1][b-1]+l[a+1][b]+l[a][b-1]+l[a][b]==4:
    print(i+1)
    h=1
    break
if h==0:
  print(0)
  
