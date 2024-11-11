for _ in range(int(input())):
  s,a,b,c=map(int,input().split())
  p=s//c
  j=(p//a)*b
  print(p+j)