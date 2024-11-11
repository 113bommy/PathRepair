z=lambda u:any(x in ''.join(y)for x in['WS','SW']for y in u)
r,c=map(int,input().split())
a=[input().replace(".","D")for _ in[0]*r]
if z(a)or z([*zip(*a)]):print('No')
else:
  print('Yes')
  for x in a:print(x)