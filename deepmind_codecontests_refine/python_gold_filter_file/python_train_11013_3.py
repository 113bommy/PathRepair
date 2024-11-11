N,K,Q=map(int,input().split())
QL=[0]*Q
NL=[K-Q]*N
for i in range(Q):
  QL[i]=int(input())-1
  NL[QL[i]]+=1
for i in range(N):
  print('Yes' if NL[i]>0 else 'No')