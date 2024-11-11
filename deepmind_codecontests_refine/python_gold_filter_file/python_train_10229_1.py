for _ in range(int(input())):
  a,b,n = list(map(int,input().split()))
  i = 0
  while True:
    if a>n or b>n:
      break
    if a> b:
      b = b +a
    else:
      a = a +b
    i+=1
  print(i)