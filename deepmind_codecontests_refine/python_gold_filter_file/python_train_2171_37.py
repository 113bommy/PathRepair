a,b,c=map(int,input().split())
num=0
while (a%2==0 and b%2==0 and c%2==0):
  a,b,c=(b//2+c//2),(a//2+c//2),(a//2+b//2)
  num+=1
  if (num>10**7):
    print(-1)
    break
else:
  print(num)