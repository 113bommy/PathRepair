for e in iter(input,'0'):
 a=[list(map(int,input().split()))for _ in[0]*int(e)]
 b=[list(map(int,input().split()))for _ in[0]*int(input())]
 for s,t in b:
  u,v=a[0]
  x,y=s-u,t-v
  for u,v in a:
   if[u+x,v+y]not in b:break
  else:print(x,y)
