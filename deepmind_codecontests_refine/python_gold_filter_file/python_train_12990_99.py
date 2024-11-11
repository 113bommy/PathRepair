A,B,N=map(int,input().split())
if B>N:
  print(A*N//B)
else:
  print(A*(B-1)//B)
