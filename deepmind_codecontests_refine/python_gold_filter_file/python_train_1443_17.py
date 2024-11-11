n=int(input())
if n==1:
  if int(input())==0:
    print(n)
  else:
    print(0)
  exit()
a=list(map(int,input().split()))
m=10**9+7
x=[]
if n%2==1:
  x.append(0)
for i in range(n%2+1,n,2):
  x.append(i)
  x.append(i)
if sorted(a)==x:
  print((2**(n//2))%m)
else:
  print(0)