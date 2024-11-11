x=int(input())
l=0
if x<2:
  print(-1)
else:
  for n in range(1,x+1):
    for k in range(n,x+1):
      if k%n==0  and (k/n)<x and k*n>x:
        print(k,n)
        l=1
        break
    if l==1:
      break