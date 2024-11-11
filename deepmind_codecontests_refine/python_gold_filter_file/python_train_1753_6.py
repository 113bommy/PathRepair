K,A,B=map(int,input().split())
if A>=K:
  print(1)
elif A<=B:
  print(-1)
else:
  bef=((K-A)//(A-B))+((K-A)%(A-B)!=0)
  print(2*bef+1)
