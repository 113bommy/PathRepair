for _ in[0]*int(input()):
  input()
  a=''.join(filter(lambda x:int(x)%2,input()))
  x=len(a)
  print([[a,a[1:]][x%2],-1][x<2])
