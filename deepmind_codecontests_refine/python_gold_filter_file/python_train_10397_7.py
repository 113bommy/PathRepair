import sys
n,k=map(int,input().split())
d=list(map(str,input().split()))
for i in range(n,100000):
  s=str(i)
  for j in d:
    if(j in s):
      break
  else:
    print(i)
    sys.exit()