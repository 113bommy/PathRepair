N=int(input())
A=list(map(int,input().split()))
m=len(set(A))
if m%2==0:
  print(m-1)
else:
  print(m)
