n=int(input())
m=1
while 2**m<=n:
  m+=1
else:
  print(2**(m-1))