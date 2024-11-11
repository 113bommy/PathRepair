N,A,B=map(int,input().split())
key=B-A
if key%2==0:
  print(int((B-A)//2))
else:
  print(int(min(A-1,N-B)+1+(B-A-1)//2))