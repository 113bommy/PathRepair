n = int(input()) 
a = list(map(int,input().split())) 
sa = sorted(a) 

if n % 2 == 0:
  k = 1
  l = 0
else:
  k = 0
  l = 1 

a=1000000007
flag = True 
for i,s in enumerate(sa):
  if ((i+l)//2)*2+k != s:
    flag = False
if flag:
  print(2**(n//2) % a)
else:
  print(0) 
