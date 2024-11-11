for i in range(int(input())):
  a,b = (map(int,input().strip().split(' ')))
  if(b==0):
    print(1)
  elif(a==0):
    print(.5)
  elif(a<=4*b):
    print(((8*b)+a)/16/b)
  else:
    print((a-b)/a)
