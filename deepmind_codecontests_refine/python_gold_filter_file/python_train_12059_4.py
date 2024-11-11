N,M=map(int,input().split())
if N==1:
  if M==1:
    print(1)
  else:
    print(M-2)
elif M==1:
  print(N-2)
else:
  print(N*M-2*max(0,N-1)-2*max(0,M-1))